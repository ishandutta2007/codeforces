#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 100010;

struct dat{
	int l, r, i;
}b[310];
int a[N], c[N], n, m, t, ans;
vector<int> res;

void solve(){
	int k=1, mn=1e9;
	rep(i,1,n)c[i]=a[i];
	rep(i,1,n){
		for(;k<=m&&b[k].r<i;++k)
			rep(j,b[k].l,b[k].r) --c[j], mn=min(mn,c[j]);
		if(a[i]-mn>ans){
			ans = c[i] - mn;
			res.clear();
			rep(j,1,k-1)res.push_back(b[j].i);
		}
		mn = min(mn, c[i]);
	}
}
bool cmp(dat a, dat b){return a.r<b.r;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,m)scanf("%d%d",&b[i].l,&b[i].r),b[i].i=i;
	sort(b+1,b+1+m,cmp);
	solve();
	rep(i,1,n/2)swap(a[i],a[n+1-i]);
	rep(i,1,m) t = b[i].l, b[i].l = n + 1 - b[i].r, b[i].r = n + 1 - t;
	sort(b+1,b+1+m,cmp);
	solve();
	printf("%d\n%d\n",ans,res.size());
	for(auto x:res)printf("%d ",x);
	return 0;
}