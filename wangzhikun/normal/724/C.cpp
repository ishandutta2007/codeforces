#include<bits/stdc++.h>
using namespace std;
int64_t h,w,k,m,i,a[200000],x,y,z,g;
int64_t q(int x, int y) {
	z=(y-x+h*w*100)%h;
	return a[z]*w+x;
}
int64_t f(int x,int y) {
	g=min(min(q(x,y),q(w - x, y)),min(q(x,h-y),q(w-x,h-y)));
	return g>m?-1:g;
}
int main() {
	cin>>w>>h>>k;
	m=w*h/__gcd(w,h);
	h*=2;
	w*=2;
	for(i=0;i<h;i++)a[i]=INT_MAX;
	for(i=h;i>=0;i--)a[w*i%h]=i;
	for(i=0;i<k;++i) {
		cin>>x>>y;
		cout<<f(x,y)<<'\n';
	}
}