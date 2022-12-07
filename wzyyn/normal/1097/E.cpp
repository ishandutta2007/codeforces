#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int q[N],a[N],vis[N];
vector<int> ans[N];
int n,res,k,f[N],fr[N];
void solve(int k){
	int mx=0; q[0]=0;
	For(i,1,n) if (!vis[a[i]]){
		int l=1,r=mx,ans=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (a[q[mid]]<a[i])
				ans=mid,l=mid+1;
			else r=mid-1;
		}
		f[i]=ans;
		fr[i]=q[ans];
		q[ans+1]=i;
		mx=max(mx,ans+1);
	}
	if (mx>=k){
		++res;
		for (int i=q[mx];i;i=fr[i])
			ans[res].PB(a[i]),vis[a[i]]=1;
		reverse(ans[res].begin(),ans[res].end());
		solve(k-1);
	}
	else{
		For(i,1,n)
			if (!vis[a[i]])
				ans[res+f[i]+1].PB(a[i]);
		res+=mx;
	}
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) vis[i]=0;
	res=0;
	for (k=1;k*(k+1)/2<=n;++k);
	solve(k);
	printf("%d\n",res);
	For(i,1,res){
		printf("%d",ans[i].size());
		for (auto j:ans[i]) printf(" %d",j);
		ans[i].resize(0);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}