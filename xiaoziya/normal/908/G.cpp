#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=705,mod=1000000007;
int n,ans,inv9;
int num[maxn],mul[maxn],cnt[10],C[maxn][maxn],muld[10][maxn],imuld[10][maxn],cc[10][maxn];
string s;
inline void inc(int &x,int y){
	x+=y;
	if(x>=mod)
		x-=mod;
}
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
void calc(int l){
	int tot=0;
	for(int d=9;d>=1;d--){
		for(int i=0;i<=n-l;i++){
			int L=tot,R=tot+cnt[d]+i-1;
			if(L<=R){
				int coef=1ll*C[n-l][i]*mul[L]%mod*(mul[R-L+1]-1+mod)%mod*inv9%mod*d%mod*muld[d][n-l-i]%mod;
				ans=(ans+1ll*coef*cc[d][n-l-i])%mod;
//				for(int j=0;j<=n-l-i;j++){
//					ans=(ans+1ll*coef*C[n-l-i][j]%mod
//					*imuld[d][j]%mod*muld[9-d][j]%mod*mul[j])%mod;
//				}
			}
		}
		tot+=cnt[d];
	}
}
int main(){
	inv9=ksm(9,mod-2);
	for(int i=0;i<=700;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>s,n=s.size();
	for(int i=1;i<=n;i++)
		num[i]=s[i-1]-48;
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=10ll*mul[i-1]%mod;
	for(int d=0;d<=9;d++){
		muld[d][0]=imuld[d][0]=cc[d][0]=1;
		int iv=ksm(d,mod-2),c=(10ll*(9-d)%mod*iv+1)%mod;
		for(int i=1;i<=n;i++){
			muld[d][i]=1ll*d*muld[d][i-1]%mod;
			imuld[d][i]=1ll*iv*imuld[d][i-1]%mod;
			cc[d][i]=1ll*cc[d][i-1]*c%mod;
		}
	}
	for(int l=0;l<=n;l++){
		if(l>0)
			cnt[num[l]]++;
		if(l==n)
			calc(l);
		else for(int c=0;c<num[l+1];c++)
			cnt[c]++,calc(l+1),cnt[c]--;
	}
	printf("%d\n",ans);
	return 0;
}