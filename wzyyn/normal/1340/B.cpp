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
const int dig[10][7]={{1,1,1,0,1,1,1},
					  {0,0,1,0,0,1,0},
					  {1,0,1,1,1,0,1},
					  {1,0,1,1,0,1,1},
					  {0,1,1,1,0,1,0},
					  {1,1,0,1,0,1,1},
					  {1,1,0,1,1,1,1},
					  {1,0,1,0,0,1,0},
					  {1,1,1,1,1,1,1},
					  {1,1,1,1,0,1,1}};
const int N=2005;
char s[N][15];
int n,k,g[N][15];
bitset<N> f[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%s",s[i]);
	f[n+1][0]=1;
	Rep(i,n,1) For(j,0,9){
		int f1=0,f2=0;
		For(k,0,6)
			if (s[i][k]=='1'&&!dig[j][k]) f1=1;
			else if (s[i][k]=='0'&&dig[j][k]) f2++;
		if (f1) g[i][j]=-1;
		else g[i][j]=f2,f[i]|=f[i+1]<<f2;
		//cout<<i<<' '<<j<<' '<<f1<<' '<<f2<<endl;
	}
	if (!f[1][k]) puts("-1");
	else
		For(i,1,n) Rep(j,9,0)
			if (g[i][j]!=-1&&g[i][j]<=k&&f[i+1][k-g[i][j]]){
				k-=g[i][j],printf("%d",j); break;
			}
}