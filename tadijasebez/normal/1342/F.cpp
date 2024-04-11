#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
pii operator + (pii a,pii b){return {a.f+b.f,b.s};}
int ri(){int x;scanf("%i",&x);return x;}
const int H=15;
const int N=1<<H;
const int inf=1e9+7;
pair<int,int> dp[H+1][N];
int pc[N],sum[N],a[N],go[H+1][N],pos[H];
int main(){
	for(int t=ri();t--;){
		int n=ri();
		for(int i=0;i<n;i++)a[i]=ri();
		for(int i=0;i<=n;i++)for(int j=0;j<1<<n;j++)dp[i][j]={inf,inf};
		for(int i=0;i<1<<n;i++){
			pc[i]=sum[i]=0;
			for(int j=0;j<n;j++)
				if(i>>j&1)
					pc[i]++,
					sum[i]+=a[j];
		}
		dp[0][0]={0,0};
		for(int i=0;i<n;i++)
			for(int mask=0;mask<1<<n;mask++){
				if(dp[i][mask]<dp[i+1][mask])
					dp[i+1][mask]=dp[i][mask],
					go[i+1][mask]=mask;
				if(!(mask>>i&1)){
					int ost=mask^((1<<n)-1);
					for(int sub=ost;sub;sub=(sub-1)&ost){
						if((sub>>i&1) && dp[i][mask].s<sum[sub] && dp[i+1][mask|sub]>dp[i][mask]+(pii){pc[sub]-1,sum[sub]})
							dp[i+1][mask|sub]=dp[i][mask]+(pii){pc[sub]-1,sum[sub]},
							go[i+1][mask|sub]=mask;
					}
				}
			}
		vector<pii> ans;
		int mask=(1<<n)-1;
		for(int i=n;i>=1;mask=go[i][mask],i--)
			if(mask!=go[i][mask])
				ans.pb({i-1,go[i][mask]^mask});
		for(int i=0;i<n;i++)pos[i]=i+1;
		vector<pii> op;
		for(auto o:ans){
			for(int i=0;i<n;i++)
				if((o.s>>i&1) && i!=o.f){
					op.pb({pos[i],pos[o.f]});
					for(int j=i;j<n;j++)pos[j]--;
				}
		}
		printf("%i\n",op.size());
		for(auto o:op)printf("%i %i\n",o.f,o.s);
	}
	return 0;
}