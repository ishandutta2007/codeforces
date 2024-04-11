#include "bits/stdc++.h"
using namespace std;
const int N=80,P=1000000007,M=1<<20;
int f[N][M],n,s[N],ans,tmp,nxt[N],Lim[N];
void limit(){
	Lim[1]=1;Lim[3]=1;Lim[5]=1;
	for(int i=1;i<=4;i++)Lim[i*3+5]=1;
	for(int i=1;i<=8;i++)Lim[17+i*4]=1;
	for(int i=1;i<=5;i++)Lim[49+i*5]=1;
	for(int i=1;i<=75;i++)Lim[i]+=Lim[i-1];
}
inline void upd(int x,int y){
	int i=nxt[x+1],z=1;
	while (i<=n && z<=Lim[n]){
		(f[i][y|(1<<z-1)]+=f[x][y])%=P;
		i++, z=(z<<1)+s[i];
	}
}
int main(){
	scanf("%d",&n);char ch;limit();
	for(int i=1;i<=n;i++){for(ch=getchar();ch<'0'||ch>'9';ch=getchar());s[i]=ch-'0';}
	for(int i=n;i>=1;i--)nxt[i]=s[i]==1?i:nxt[i+1];
	f[0][0]=1;upd(0,0);int lim;
	for(int i=1;i<n;i++){
		f[i][0]=1;lim=1<<Lim[n];if(nxt[i+1]==n+1)break;
		for(int j=0;j<lim;j++)if(f[i][j])upd(i,j);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=Lim[i];j++)
			(ans+=f[i][(1<<j)-1])%=P;
	printf("%d\n",ans);
	return 0;
}