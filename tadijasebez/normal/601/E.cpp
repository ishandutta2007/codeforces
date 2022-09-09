#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int K=1050;
const int inf=1e9+7;
const int mod=1e9+7;
const int base=1e7+19;
void ckmx(int &x,int y){x=max(x,y);}
int n,k,q;
int dp[2][K];
void cl(int j){for(int i=0;i<=k;i++)dp[j][i]=0;}
void upd(int j,int w,int v){
	for(int i=k;i>=w;i--)ckmx(dp[j][i],dp[j][i-w]+v);
}
void cpy(int a,int b){for(int i=0;i<=k;i++)dp[a][i]=dp[b][i];}
int hsh(int j){int ans=0;for(int i=1,p=1;i<=k;i++,p=(ll)p*base%mod)ans=(ans+(ll)dp[j][i]*p)%mod;return ans;}
void p(int j){for(int i=1;i<=k;i++)printf("%i ",dp[j][i]);printf("\n");}
const int S=173*4;
const int N=30005;
bool mark[N],active[N];
int w[N],v[N],t[N],x[N],ans[N];
int main(){
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%i %i",&v[i],&w[i]);
		active[i]=1;
	}
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i",&t[i]);
		if(t[i]==1){
			x[i]=++n;
			scanf("%i %i",&v[n],&w[n]);
		}else if(t[i]==2){
			scanf("%i",&x[i]);
		}
	}
	for(int l=1;l<=q;l+=S){
		int r=min(q,l+S-1);
		vector<int> work;
		for(int i=l;i<=r;i++)if(t[i]!=3)mark[x[i]]=1,work.pb(x[i]);
		sort(work.begin(),work.end());
		work.erase(unique(work.begin(),work.end()),work.end());
		cl(0);
		for(int i=1;i<=n;i++)if(active[i] && !mark[i])upd(0,w[i],v[i]);
		for(int i=l;i<=r;i++){
			if(t[i]==1)active[x[i]]=1;
			if(t[i]==2)active[x[i]]=0;
			if(t[i]==3){
				cpy(1,0);
				for(int j:work)if(active[j])upd(1,w[j],v[j]);
				ans[i]=hsh(1);
			}
		}
		for(int i=l;i<=r;i++)if(t[i]!=3)mark[x[i]]=0;
	}
	for(int i=1;i<=q;i++)if(t[i]==3)printf("%i\n",ans[i]);
	return 0;
}