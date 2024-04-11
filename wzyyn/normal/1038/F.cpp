#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=45;
int ch[N][2],fa[N];
ll f[N][N],g[N][N],ans;
int n,m;
char s[N];
void build_mat(){
	fa[1]=0;
	For(i,1,m){
		fa[i]=ch[fa[i-1]][s[i]];
		ch[i-1][s[i]^1]=ch[fa[i-1]][s[i]^1];
		ch[i-1][s[i]]=i;
		//cout<<ch[i-1][0]<<' '<<ch[i-1][1]<<endl;
	}
	ch[m][0]=ch[fa[m]][0];
	ch[m][1]=ch[fa[m]][1];
}
int main(){
	scanf("%d%s",&n,s+1);
	m=strlen(s+1);
	For(i,1,m) s[i]-='0';
	build_mat();
	f[0][m]=1; g[0][m]=1;
	For(i,1,n) For(j,0,m){
		f[i][ch[j][0]]+=f[i-1][j];
		f[i][ch[j][1]]+=f[i-1][j];
	}
	For(i,1,n) For(j,0,m-1){
		g[i][j]+=g[i-1][ch[j][0]];
		g[i][j]+=g[i-1][ch[j][1]];
	}
	For(i,1,n) For(j,0,m)
		ans+=f[i][j]*g[n-i][j];
	printf("%lld\n",ans);
}