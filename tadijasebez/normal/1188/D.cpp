#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050,L=60;
ll a[N],mx;int dp[L][N],ord[N],tmp[N],cnt[2],n;
void ckmx(ll &x,ll y){x=max(x,y);}
void ckmn(int &x,int y){x=min(x,y);}
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),ckmx(mx,a[i]);
	for(int i=1;i<=n;i++)a[i]=mx-a[i],ord[i]=i;
	for(int i=0;i<L;i++)for(int j=0;j<N;j++)dp[i][j]=1e9;
	dp[0][0]=0;
	for(int j=0;j<L-1;j++){
		for(int i=1;i<=n;i++)cnt[a[i]>>j&1]++;
		int o=cnt[1],l=0;
		for(int i=0;i<=n;i++){
			ckmn(dp[j+1][l],dp[j][i]+o);
			ckmn(dp[j+1][l+o],dp[j][i]+n-o);
			if(i==n)break;
			if(a[ord[i+1]]>>j&1)o--,l++;
			else o++;
		}
		cnt[0]+=cnt[1];
		for(int i=n;i>=1;i--)tmp[cnt[a[ord[i]]>>j&1]--]=ord[i];
		for(int i=1;i<=n;i++)ord[i]=tmp[i];
		cnt[0]=cnt[1]=0;
	}
	printf("%i\n",dp[L-1][0]);
	return 0;
}