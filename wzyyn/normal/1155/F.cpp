#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=14+5,M=(1<<14)+5;
struct node{
	int p1,p2,S;
};
int cnt[M],e[N][N];
int f[N][N][M];
int fr[N][N][M];
int g[M],n,m;
node gr[M];
void init_pth(){
	For(i,1,(1<<n)-1) cnt[i]=cnt[i/2]+(i&1); 
	For(i,0,n-1) f[i][i][1<<i]=1;
	For(S,0,(1<<n)-1)
		For(i,0,n-1) For(j,0,n-1)
			if (f[i][j][S]) 
				For(k,0,n-1) if (!(S&(1<<k))&&e[j][k]){
					f[i][k][S|(1<<k)]=1;
					fr[i][k][S|(1<<k)]=j;
				}
}
void calc_ans(){
	memset(g,10,sizeof(g));
	For(i,0,n-1) For(j,0,n-1) if (e[i][j])
		For(k,0,(1<<n)-1) if (f[i][j][k]&&cnt[k]>2)
			g[k]=cnt[k],gr[k]=(node){i,j,k};
	For(i,0,(1<<n)-1) if (g[i]<1<<20){
		int opp=(1<<n)-1-i;
		for (int j=opp;j;j=(j-1)&opp){
			For(p1,0,n-1) if (i&(1<<p1))
				For(p2,p1+1,n-1) if (i&(1<<p2))
					if (f[p1][p2][j|(1<<p1)|(1<<p2)]&&g[i|j]>g[i]+cnt[j]+1){
						g[i|j]=g[i]+cnt[j]+1;
						gr[i|j]=(node){p1,p2,j};
					}
			if (cnt[j]!=1){
				For(p1,0,n-1) if (i&(1<<p1))
					For(p2,0,n-1) if ((j&(1<<p2))&&e[p1][p2])
						if (f[p1][p2][j|(1<<p1)|(1<<p2)]&&g[i|j]>g[i]+cnt[j]+1){
							g[i|j]=g[i]+cnt[j]+1;
							gr[i|j]=(node){p1,p2,j};
						}
			}
		}
	}
}
void output_ans(){
	for (int S=(1<<n)-1;S;){
		//printf("part %d %d\n",S,g[S]);
		int p1=gr[S].p1,p2=gr[S].p2,del=gr[S].S;
		if (del&(1<<p2)) printf("%d %d\n",p1+1,p2+1);
		S-=del; del|=(1<<p1)|(1<<p2);
		for (;cnt[del]!=1;){
			int p3=fr[p1][p2][del];
			printf("%d %d\n",p2+1,p3+1);
			del-=(1<<p2); p2=p3;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		--x; --y;
		e[x][y]=e[y][x]=1;
	}
	init_pth();
	calc_ans();
	printf("%d\n",g[(1<<n)-1]);
	output_ans();
}