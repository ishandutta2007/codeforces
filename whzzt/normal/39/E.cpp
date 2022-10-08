#include<bits/stdc++.h>
using namespace std;
const char s[][10]={"Stas","Masha","Missing"}; 
const int N=32005,M=35;
long long fpm(int a,int t){long long r;for(r=1;t;t>>=1,a*=a)if(t&1)r*=a;return r;}
int n,m,L,f[N][M];
bool v[N][M];
int dfs(int x,int y){
	if(v[x][y])return f[x][y];
	v[x][y]=true;
	if(fpm(x,y)>=L)return f[x][y]=1;
	if((1<<y)>=L)return f[x][y]=2;
	if(x*x>=L)return ~(L-x)&1;
	int p=dfs(x+1,y),q=dfs(x,y+1);
	if(p==0||q==0)return f[x][y]=1;
	if(p==2||q==2)return f[x][y]=2;
	return f[x][y]=0;
}
int main(){scanf("%d%d%d",&n,&m,&L),puts(s[dfs(n,m)]);}