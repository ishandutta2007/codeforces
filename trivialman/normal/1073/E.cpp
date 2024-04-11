#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

struct sn{
	LL s,n;
}dp[25][10][1024];
LL exp10[25];
LL a[25],l,r,k;

sn dfs(int nth,int x,int j,bool tie){
	//
	if(nth==0){
		dp[0][x][j]={x,1};
		return dp[0][x][j];
	}
	if(!tie&&(dp[nth][x][j].s||dp[nth][x][j].n))return dp[nth][x][j];
	LL end=tie?a[nth]:9,ss=0,nn=0;
	rep(i,0,end){
		int newj = (j==0&&i==0)?0:j|(1<<i);
		if(__builtin_popcount(newj)<=k){
			sn tmp=dfs(nth-1,i,newj,tie&&i==end);
			nn+=tmp.n;ss+=tmp.s;
		}
	}
	sn res={(ss+nn*x%MOD*exp10[nth]%MOD)%MOD,nn%MOD};
	if(!tie)dp[nth][x][j]=res;
	return res;
}

LL calc(LL n){
	int digits=0;
	CL(a);CL(dp);
	for(;n;n/=10)a[++digits]=n%10;
	return dfs(digits,0,0,true).s;
}

int main(){
	cin>>l>>r>>k;
	exp10[0]=1;
	rep(i,1,20)exp10[i]=(exp10[i-1]*10)%MOD;
	cout<<(calc(r)-calc(l-1)+MOD)%MOD<<endl;
	return 0;
}