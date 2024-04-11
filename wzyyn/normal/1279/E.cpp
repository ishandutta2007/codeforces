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
const int N=55;
const ll INF=1ll<<61;
ll ADD(ll x,ll y){
	return min(INF,x+y);
}
ll MUL(ll x,ll y){
	if (!x) return 0;
	return INF/x<y?INF:min(INF,x*y);
}
ll f[N],ff[N],g[N],k;
int n,vis[N],ans[N];
int ed[N],cnt[N],S[N];
int mn[N],mx[N],SS[N];
void init(){
	f[1]=f[2]=f[3]=g[0]=1;
	For(i,4,N-1) f[i]=MUL(f[i-1],i-2);
	For(i,0,N-1) For(j,i+1,N-1)
		g[j]=ADD(g[j],MUL(g[i],f[j-i]));
}
ll Func(){
	static int vis[55];
	memset(vis,0,sizeof(vis));
	memset(ed,0,sizeof(ed));
	memset(cnt,0,sizeof(cnt));
	memset(S,0,sizeof(S));
	memset(SS,0,sizeof(SS));
	memset(ff,0,sizeof(ff));
	For(i,1,n){
		++*vis;
		int x=i;
		//printf("%d %d\n",vis[x],*vis);
		for (;x&&vis[x]!=*vis;x=ans[x])
			vis[x]=*vis,++cnt[i];
		ed[i]=x;
		//printf("INF %d %d %d\n",i,x,cnt[i]);
		if (x==i){
			int mn=1<<30,mx=0;
			for (int j=i;;j=ans[j]){
				S[j]=1;
				mn=min(mn,j);
				mx=max(mx,j);
				if (ans[j]==i) break;
			}
			if (mx-mn+1!=cnt[i])
				return 0;
		}
	}
	For(i,1,n) S[i]+=S[i-1];
	For(i,1,n) SS[i]=SS[i-1]+(ans[i]!=0);
	ff[0]=1;
	For(i,1,n){
		if (S[i]!=S[i-1]){
			ff[i]=ff[i-1];
			continue;
		}
		mn[i]=mx[i]=(ans[i]?ans[i]:i);
		Rep(j,i-1,1){
			mn[j]=min(mn[j+1],ans[j]?ans[j]:j);
			mx[j]=max(mx[j+1],ans[j]?ans[j]:j);
		}
		Rep(j,i-1,0){
			//printf("TR %d %d\n",i,j);
			if (S[i]!=S[j]||mn[j+1]<j+1||mx[j+1]>i) continue;
			if (ans[j+1]&&ans[j+1]!=i) continue;
			//printf("TR %d %d\n",i,j);
			if (ed[i]==j+1&&cnt[i]!=i-j+1) continue;
			int sum=SS[i]-SS[j+1]; sum=i-j-1-sum;
			//printf("TR %d %d %d\n",i,j,sum);
			ff[i]=ADD(ff[i],MUL(ff[j],f[sum+1]));
		}
	}
	//printf("RES=%lld\n",ff[n]);
	return ff[n];
}
void solve(){
	scanf("%d%lld",&n,&k);
	if (k>g[n]) return puts("-1"),void(0);
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	int pos=1; ++*vis;
	for (;g[n-pos]>k;pos++);
	For(i,1,pos-1) ans[i]=i,vis[i]=1;
	//printf("ANS %d %lld %lld\n",pos,Func(),g[n-pos+1]);
	//return;
	For(i,pos,n)
		for (ans[i]=pos;;++ans[i]){
			//if (n==6) printf("Q %d %d %d\n",i,ans[i],n);
			if (vis[ans[i]]==1) continue;
			vis[ans[i]]=1;
			ll v=Func();
			if (v>=k) break;
			vis[ans[i]]=0;
			k-=v;
		}
	//printf("%d ",n);
	For(i,1,n)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	//freopen("1.in","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}