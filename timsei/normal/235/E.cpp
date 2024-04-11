using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 20001
#define int long long
#define ll long long
int p[N],cnt,mu[N],A,B,C,G[2001][2001];
bool isp[N];
void prework() {
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;mu[1]=1;
	for(int i=2;i<=3000;i++) {
		if(isp[i]) p[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&p[j]*i<=3000;j++) {
			isp[i*p[j]]=0;
			if(i%p[j]==0) {
				mu[i*p[j]]=0;break;
			}
			else mu[i*p[j]]=-mu[i];
		}
	}
}
int gcd(int x,int y) {
	if(G[x][y]) return G[x][y];
	return y==0?x:G[x][y]=G[y][x]=gcd(y,x%y);
}
int cal(int d,int x) {
	int res=0;
	for(int i=1;i<=d;i++) {
		if(gcd(i,x)==1) {
			res=(res+(d/i));
		}
	}
	return res;
}
main() {
	scanf("%lld%lld%lld",&A,&B,&C);
	prework();int ans=0;
	int mod=1<<30;
	for(int i=1;i<=A;i++) {
		for(int j=1;j<=min(B,C);j++) {
			if(gcd(i,j)==1) {
				ans=(ans+mu[j]*cal(B / j, i ) * cal( C / j , i )*( A / i ))%mod;
			}
		}
	}
	printf("%lld\n",ans);
}