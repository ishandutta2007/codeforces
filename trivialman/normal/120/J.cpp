#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 3e5+5;
 
struct Point{
	int x,y,k,id;
}a[N],t[N];
int n,x,y;
double d = 1e10;
array<int, 4> ans;
 
void solve(int l,int r){
	if(l>=r) return;
	int m = l+r>>1;
	int x = a[m].x + a[m+1].x >> 1;
	solve(l,m), solve(m+1,r);
	
	int k = m, j = m+1, i;
	rep(i,m+1,r) if(a[i].x<=x+d) t[++k] = a[i];
	rep(i,l,m) if(a[i].x>=x-d) {
		while(j>m+1 && t[j].y>a[i].y-d) --j;
		for(; j<=k && t[j].y<a[i].y+d; ++j){
			if(a[i].id==t[j].id) continue;
			double dx = t[j].x - a[i].x, dy = t[j].y - a[i].y;
			double d1 = sqrt(dx*dx + dy*dy);
			if(d1<d){
				d = d1;
				ans = {a[i].id,a[i].k,t[j].id,5-t[j].k};
			}
		}
		if(j>k) --j;
	}
	rep(i,l,m) t[i] = a[i];
	rep(i,m+1,r) t[i] = a[m+r+1-i];
	i = l, j = r, k = l;
	while(i<=j) a[k++] = t[i].y<t[j].y ? t[i++] : t[j--];
	return;
}
 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		a[i] = {x,y,1,i};
		a[n+i] = {-x,y,2,i};
		a[n+n+i] = {x,-y,3,i};
	}
	n *= 3;
	sort(a+1,a+n+1,[](Point x,Point y){return x.x<y.x;});
	solve(1,n);
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
	return 0;
}