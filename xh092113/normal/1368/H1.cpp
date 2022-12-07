#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1e5;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int f[N+5][2],g[N+5][2]; // fg
bool l[N+5],r[N+5],u[N+5],d[N+5];
int n,m,q;
char s[N+5];

int main(){
//	freopen("CF1368H1.in","r",stdin);
//	freopen("CF1368H1.out","w",stdout);
	n = read(),m = read(),q = read();
	scanf("%s",s + 1); for(rg int i = 1;i <= n;i++)l[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= n;i++)r[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= m;i++)u[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= m;i++)d[i] = (s[i] == 'B');
	
	//horional
	for(rg int i = 1;i <= m;i++)if(u[i])f[1][0]++;else f[1][1]++;
	f[1][0] += (l[1] != 0) + (r[1] != 0);
	f[1][1] += (l[1] != 1) + (r[1] != 1);
	for(rg int i = 2;i <= n;i++){
		f[i][0] = min(f[i-1][0],f[i-1][1] + m) + (l[i] != 0) + (r[i] != 0);
		f[i][1] = min(f[i-1][0] + m,f[i-1][1]) + (l[i] != 1) + (r[i] != 1);
	}
	for(rg int i = 1;i <= m;i++)if(d[i])f[n][0]++;else f[n][1]++;
	
	//vertical
	for(rg int i = 1;i <= n;i++)if(l[i])g[1][0]++;else g[1][1]++;
	g[1][0] += (u[1] != 0) + (d[1] != 0);
	g[1][1] += (u[1] != 1) + (d[1] != 1);
	for(rg int i = 2;i <= m;i++){
		g[i][0] = min(g[i-1][0],g[i-1][1] + n) + (u[i] != 0) + (d[i] != 0);
		g[i][1] = min(g[i-1][0] + n,g[i-1][1]) + (u[i] != 1) + (d[i] != 1);
	}
	for(rg int i = 1;i <= n;i++)if(r[i])g[m][0]++;else g[m][1]++;

//for(rg int i = 1;i <= n;i++)cout<<"i="<<i<<" f0="<<f[i][0]<<" f1="<<f[i][1]<<endl;
//for(rg int i = 1;i <= m;i++)cout<<"i="<<i<<" g0="<<g[i][0]<<" g1="<<g[i][1]<<endl;
	
	write(min(min(f[n][0],f[n][1]),min(g[m][0],g[m][1]))),putchar('\n');
	return 0;
}