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
const int mo=1000000007;
const int N=100005;
int n,Q,ans[N];
int a[N],P[N],s[N];
int f[N],pre[N],sp[N];
int sum[N];
vector<pii> vQ[N];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
void merge(int x,int y){
	if (x-pre[x]>31&&sum[y]>0) sum[y]=mo;
	else if (sum[x]+(1ll<<(x-pre[x]))*sum[y]>mo) sum[y]=mo;
	else sum[y]=sum[x]+(1ll<<(x-pre[x]))*sum[y];
	f[x]=f[y]; pre[y]=pre[x];
}
int ask(int x,int y){
	return (s[x]+mo-1ll*s[y+1]*P[y-x+1]%mo)%mo;	
}
int main(){
	P[0]=1;
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) f[i]=i,pre[i]=i-1;
	For(i,1,n) P[i]=2ll*P[i-1]%mo;
	Rep(i,n,1) s[i]=(2ll*s[i+1]+a[i])%mo;
	For(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		vQ[r].PB(pii(l,i));
	}
	For(i,1,n){
		sum[i]=a[i];
		for (;pre[i]&&sum[i]>=0;merge(pre[i],i));
		sp[i]=(sp[pre[i]]+2ll*ask(pre[i]+1,i))%mo;
		for (auto j:vQ[i]){
			int a=j.fi,b=get(a);
			ans[j.se]=(1ll*sp[i]-sp[b]+mo+1ll*ask(a,b))%mo;
		}
	}
	For(i,1,Q)
		printf("%d\n",(ans[i]%mo+mo)%mo);
}