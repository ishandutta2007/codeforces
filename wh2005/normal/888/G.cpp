#include<bits/stdc++.h>
using namespace std;
const int N=200009;
#define ll long long
int n,a[N],t[N*32][2],tot;
int siz[N*32];ll ans;
void Min(ll &x,ll y){if(x>y) x=y;}
void tinsert(int x){
	int c=0;
	for(int i=30;i>=0;i--){
		int p=(x>>i)&1;
		if(!t[c][p]) t[c][p]=++tot;
		c=t[c][p],siz[c]++;
	}
}
ll Get(int c,int x,int d){
	ll ans=(1<<d);
	for(int i=d-1;i>=0;i--){
		int p=(x>>i)&1;
		if(t[c][p]) c=t[c][p];
		else c=t[c][!p],ans|=(1<<i);
	}
	return ans;
}
void solve(int c,int l,int r,int d){
	if(d<0) return ;
	if(!t[c][0]&&!t[c][1]) return ;
	if(!t[c][0]) solve(t[c][1],l,r,d-1);
	else if(!t[c][1]) solve(t[c][0],l,r,d-1);
	else {
		int mid=l+siz[t[c][0]]-1;
		ll val = 1e16;
		solve(t[c][0],l,mid,d-1);solve(t[c][1],mid+1,r,d-1);
		for(int i=l;i<=mid;i++)
			Min(val,Get(t[c][1],a[i],d-1));
		ans+=val;
	}
}
int main(){
	memset(t,0,sizeof(t));
	scanf("%d",&n);tot=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++) tinsert(a[i]);
	ans=0;solve(0,1,n,31);
	printf("%lld\n",ans);
	return 0;
}