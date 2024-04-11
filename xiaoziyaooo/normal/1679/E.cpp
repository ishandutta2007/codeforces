#include<stdio.h>
#include<iostream>
using namespace std;
const int mod=998244353,maxn=20,maxl=1005;
int n,q,m;
int f[maxn][1<<17],mul[maxn][maxl],imul[maxn][maxl];
string s,t;
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	scanf("%d",&n),cin>>s,scanf("%d",&q),s=" "+s;
	for(int i=1;i<=n;i++)
		m+=(s[i]=='?');
	for(int i=1;i<=17;i++){
		mul[i][0]=imul[i][0]=1;
		int v0=i,v1=ksm(i,mod-2);
		for(int j=1;j<=n;j++)
			mul[i][j]=1ll*mul[i][j-1]*v0%mod,imul[i][j]=1ll*imul[i][j-1]*v1%mod;
	}
	for(int c=1;c<=17;c++){//ji de gai
		for(int i=1;i<=n;i++){
			int x=i,y=i,S=0,t=0;
			while(x>=1&&y<=n){
				if(s[x]!='?'&&s[y]!='?'&&s[x]!=s[y])
					break;
				if(s[x]=='?'&&s[y]!='?')
					S|=(1<<(s[y]-97)),t++;
				if(s[x]!='?'&&s[y]=='?')
					S|=(1<<(s[x]-97)),t++;
				if(x<y&&s[x]=='?'&&s[y]=='?')
					t++;
//				printf("x=%d y=%d c=%d S=%d t=%d\n",x,y,c,S,t);
				f[c][S]=(f[c][S]+imul[c][t])%mod;
				x--,y++;
			}
		}
		for(int i=1;i<n;i++){
			int x=i,y=i+1,S=0,t=0;
			while(x>=1&&y<=n){
				if(s[x]!='?'&&s[y]!='?'&&s[x]!=s[y])
					break;
				if(s[x]=='?'&&s[y]!='?')
					S|=(1<<(s[y]-97)),t++;
				if(s[x]!='?'&&s[y]=='?')
					S|=(1<<(s[x]-97)),t++;
				if(s[x]=='?'&&s[y]=='?')
					t++;
				f[c][S]=(f[c][S]+imul[c][t])%mod;
//				printf("x=%d y=%d c=%d S=%d t=%d\n",x,y,c,S,t);
				x--,y++;
			}
		}
		for(int len=2,now=1;len<=(1<<17);len<<=1,now<<=1)
			for(int i=0;i<(1<<17);i+=len)
				for(int j=0;j<now;j++)
					f[c][i+j+now]=(f[c][i+j+now]+f[c][i+j])%mod;
	}
	while(q--){
		int x,S=0;
		cin>>t;
		for(int i=0;i<t.size();i++)
			S|=(1<<(t[i]-97));
		printf("%d\n",1ll*f[t.size()][S]*mul[t.size()][m]%mod);
	}
	return 0;
}