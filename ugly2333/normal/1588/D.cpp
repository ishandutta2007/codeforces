//CF1588D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 22;
const int M = 55;
const int L = 111;
int n,m=52,l[N],a[N][M][2],f[N][L][M];
char s[L];
int toi(char c){
	if('a'<=c&&c<='z')
		return c-'a'+1;
	return c-'A'+27;
}
int g[M][1<<10],h[M][1<<10][2];
int b[N];
void solve(int j,int x){
	if(g[j][x])
		return;//cout<<j<<' '<<x<<endl;
	g[j][x]=1;
	int i,k,y,o;
	for(k=1;k<=m;k++){
		o=1;
		y=0;
		for(i=0;i<n;i++){
			b[i]=a[i][j][(x>>i)&1];
			if(f[i][b[i]+1][k]>l[i]){
				o=0;
				break;
			}
			if(f[i][b[i]+1][k]==a[i][k][1])
				y|=1<<i;
		}
		if(o){
			solve(k,y);
			if(g[j][x]<g[k][y]+1){
				h[j][x][0]=k,h[j][x][1]=y;
				g[j][x]=g[k][y]+1;
			}
		}
	}
}
int main()
{
	int T,i,j,k,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		for(i=0;i<n;i++){
			scanf("%s",s+1);
			l[i]=strlen(s+1);
			for(j=1;j<=l[i];j++){
				x=toi(s[j]);
				if(a[i][x][0])
					a[i][x][1]=j;
				else
					a[i][x][0]=j;
				f[i][j][x]=j;
			}
			for(j=1;j<=m;j++)
				f[i][l[i]+1][j]=L;
			for(j=l[i];j>=1;j--)
				for(k=1;k<=m;k++)
					if(!f[i][j][k])
						f[i][j][k]=f[i][j+1][k];
		}
		solve(0,0);
		printf("%d\n",g[0][0]-1);
		for(i=h[0][0][0],j=h[0][0][1];i;i=k,j=x){
			//cout<<i<<j<<endl;
			if(i<=26)
				cout<<(char)(i-1+'a');
			else
				cout<<(char)(i-27+'A');
			k=h[i][j][0],x=h[i][j][1];
		}
		cout<<endl;
	}
	return 0;
}