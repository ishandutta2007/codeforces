#include<stdio.h>
const int maxn=405,maxk=30,mod=998244353;
int n,ans0,ans1,ans2;
int cnt[maxk],f[2][maxn][maxn][9],g[maxn][maxn][4],h[maxn];
inline void inc(int &x,int y){
	x+=y;
	if(x>=mod)
		x-=mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=26;i++)
		scanf("%d",&cnt[i]);
	h[2]=26*26;
	for(int i=3;i<=n;i++)
		h[i]=25ll*h[i-1]%mod;
	g[2][0][0]=25*25,g[2][1][1]=25,g[2][1][2]=25,g[2][2][3]=1;
	for(int i=3;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int c=0;c<4;c++)
				if(g[i-1][j][c]){
					int d=(c&1)<<1,v=g[i-1][j][c];
					if((c&2)==0)
						inc(g[i][j+1][d|1],v);
					g[i][j][d]=(g[i][j][d]+1ll*(24+((c&2)==0? 0:1))*v)%mod;
				}
	for(int a=0;a<3;a++)
		for(int b=0;b<3;b++)
			f[0][(a==1)+(b==1)][(a==2)+(b==2)][a*3+b]=(a==0? 24:1)*(b==0? 24:1);
	int now=0;
	for(int i=3;i<=n;i++){
		now^=1;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				for(int c=0;c<9;c++)
					f[now][j][k][c]=0;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				for(int c=0;c<9;c++)
					if(f[now^1][j][k][c]){
						int d=(c%3)*3,v=f[now^1][j][k][c];
						if(c/3!=1)
							inc(f[now][j+1][k][d+1],v);
						if(c/3!=2)
							inc(f[now][j][k+1][d+2],v);
						f[now][j][k][d]=(f[now][j][k][d]+1ll*(23+((c/3==1||c/3==2)? 1:0))*v)%mod;
					}
	}
	ans0=h[n];
	for(int i=1;i<=26;i++)
		for(int j=cnt[i]+1;j<=n;j++)
			for(int c=0;c<4;c++)
				ans1=(ans1+g[n][j][c])%mod;
	for(int i=1;i<=26;i++)
		for(int j=i+1;j<=26;j++)
			for(int a=cnt[i]+1;a<=n;a++)
				for(int b=cnt[j]+1;b<=n;b++)
					for(int c=0;c<9;c++)
						ans2=(ans2+f[now][a][b][c])%mod;
	printf("%d\n",(0ll+ans0-ans1+ans2+mod)%mod);
	return 0;
}