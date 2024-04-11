#include<bits/stdc++.h>
using namespace std;
int n,m,f[1001000][8],sta[1001000],cnt[8],res=0x3f3f3f3f;
char s[1001000];
int main(){
	scanf("%d%d",&n,&m),memset(f,0x3f,sizeof(f));
	if(n>=4){puts("-1");return 0;}
	if(n==1){puts("0");return 0;}
	for(int i=0;i<n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)if(s[j]=='1')sta[j]|=(1<<i);
	}
	for(int i=0;i<8;i++)cnt[i]=__builtin_popcount(i);
	if(n==2){
		for(int i=0;i<4;i++)f[1][i]=cnt[i^sta[1]];
		for(int i=2;i<=m;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)if((cnt[j]+cnt[k])&1)f[i][j]=min(f[i][j],f[i-1][k]+cnt[j^sta[i]]);
		for(int i=0;i<4;i++)res=min(res,f[m][i]);
		printf("%d\n",res);
	}else{
		for(int i=0;i<8;i++)f[1][i]=cnt[i^sta[1]];
		for(int i=2;i<=m;i++)for(int j=0;j<8;j++)for(int k=0;k<8;k++)if(((cnt[j&3]+cnt[k&3])&1)&&((cnt[j&6]+cnt[k&6])&1))f[i][j]=min(f[i][j],f[i-1][k]+cnt[j^sta[i]]);
		for(int i=0;i<8;i++)res=min(res,f[m][i]);
		printf("%d\n",res);
	}
	return 0;
}