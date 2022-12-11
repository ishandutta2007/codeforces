#include<bits/stdc++.h>
using namespace std;
map<long long,int>xh;
int pocnt,col[130005];
long long dp[120005][7],mod=1e9+7;
struct edge{
	int to,nex;
};
edge ed[150005];
int cnt,h[150005];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nex=h[st];
	h[st]=cnt;
}
int k,n;
void dfs(int x,int fa){
	if(!col[x]){
		for(int i=1;i<=6;i++){
			dp[x][i]=1;
		}
	}
	else{
		dp[x][col[x]]=1;
	}
	for(int i=h[x];i;i=ed[i].nex){
		int v=ed[i].to;
		if(v==fa)continue;
		dfs(v,x);
		for(int o=1;o<=6;o++){
			long long sum=0;
			for(int j=1;j<=6;j++){
				if(o+j!=7&&o!=j)sum+=dp[v][j],sum%=mod;
			}
			dp[x][o]*=sum;
			dp[x][o]%=mod;
		}
	}
}
long long po(long long x,long long y,long long mo){
	long long res=1;
	while(y){
		if(y&1)res*=x,res%=mo;
		x*=x;
		x%=mo;
		y>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&k,&n);
	xh[1]=++pocnt;
	for(int i=1;i<=n;i++){
		long long x;
		string s;
		scanf("%lld",&x);
		cin>>s;
		if(!xh[x]){
			long long kk=x;
			xh[kk]=++pocnt;
			kk>>=1;
			while(!xh[kk]){
				xh[kk]=++pocnt;
				kk>>=1;
				add(pocnt,pocnt-1);
			}
			add(xh[kk],pocnt);
		}
		int draw;
		if(s[0]=='w')draw=1;
		if(s[0]=='g')draw=2;
		if(s[0]=='r')draw=3;
		if(s[0]=='o')draw=4;
		if(s[0]=='b')draw=5;
		if(s[0]=='y')draw=6;
		col[xh[x]]=draw;
	}
	dfs(1,0);
	long long pu=dp[1][1]+dp[1][2]+dp[1][3]+dp[1][4]+dp[1][5]+dp[1][6];
	pu%=mod;
	long long ans=(po(4ll,(po(2ll,k,mod-1)+mod-1-pocnt-1)%(mod-1),mod)%mod)*pu%mod;
	printf("%lld",ans);
	return 0;
}