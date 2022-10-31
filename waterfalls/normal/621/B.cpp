#include <bits/stdc++.h>
using namespace std;

int B,x,y,i,ans = 0;
map<int,int> p;

int main() {
	cin >> B;
	for (i=0;i<B;i++) {
		cin >> x >> y;
		p[x+y+1e9]+=1;
		p[x-y]+=1;
	}
	for (auto n: p) ans+=n.second*(n.second-1)/2;
	cout << ans;
}