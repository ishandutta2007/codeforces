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
const int N=2005;
int fa[N],cnt[N];
bitset<N> f[N],g[N];
int n,m;
char s[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) fa[i]=0;
	For(i,1,m){
		cnt[i]=0;
		scanf("%s",s+1);
		For(j,1,n) if (s[j]=='1')
			f[j][i]=g[i][j]=1,++cnt[i];
	}
	For(i,1,n) if (!fa[i])
		For(j,1,n) if (!fa[j]&&j!=i)
			if ((f[i]&f[j])==f[i]){
				//printf("E2 %d %d\n",i,j);
				For(l,1,m) if (f[i][l])
					f[i][l]=g[l][i]=0,--cnt[l];
				fa[i]=j; break;
			}
	For(i,1,n) For(j,1,m) if (cnt[j]==1){
		int p=0;
		For(k,1,n) if (g[j][k]==1) p=k;
		f[p][j]=g[j][p]=0; --cnt[j];
		//printf("TRY %d %d\n",j,p);
		For(k,1,n)
			if (k!=p&&!fa[k]&&!fa[p])
				if ((f[p]&f[k])==f[p]){
					//printf("E1 %d %d\n",k,p);
					For(l,1,m) if (f[p][l])
						f[p][l]=g[l][p]=0,--cnt[l];
					fa[p]=k; break;
				}
	}
	int sum=0;
	For(i,1,n) sum+=(fa[i]!=0);
	if (sum!=n-1) puts("NO");
	else{
		puts("YES");
		For(i,1,n) if (fa[i]) printf("%d %d\n",i,fa[i]);
	}
	For(i,1,n) For(j,1,m)
		f[i][j]=g[j][i]=0;
}
int main(){
	//freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--) solve();
}