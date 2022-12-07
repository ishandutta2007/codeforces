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
const int N=505;
int f[N][N][12];
int n,K,nd,dep[N],sum[N];
int ch[N][26],tmp[12];
vector<int> e[N];
char s[N];
void dfs(int x){
	memset(f[x],10,sizeof(f[x]));
	For(p,1,nd) f[x][p][0]=0;
	for (auto i:e[x]){
		dfs(i);
		For(p,1,nd){
			For(j,0,K) tmp[j]=1<<28;
			For(j,0,K) For(k,0,K-j){
				//if (p==1&&!j&&!k) cout<<f[x][p][j]<<' '<<f[i][p][k]<<endl;
				tmp[j+k]=min(tmp[j+k],f[x][p][j]+f[i][p][k]);
				tmp[j+k+1]=min(tmp[j+k+1],f[x][p][j]+f[i][i][k]);
			}
			For(j,0,K) f[x][p][j]=tmp[j];
		}
	}
	For(p,1,nd) For(j,0,K)
		f[x][p][j]+=(dep[x]-dep[p])*sum[x];
	//cout<<f[x][1][0]<<' '<<x<<endl;
}
int main(){
	nd=1;
	scanf("%d%d",&n,&K);
	For(i,1,n){
		scanf("%s",s+1);
		int l=strlen(s+1);
		int x=1;
		For(j,1,l){
			int c=s[j]-'0';
			if (!ch[x][c]){
				e[x].PB(++nd);
				dep[nd]=j;
				ch[x][c]=nd;
			}
			x=ch[x][c];
		}
		int v;
		scanf("%d",&v);
		sum[x]+=v;
	}
	//cout<<nd<<endl;
	dfs(1);
	int ans=1<<30;
	For(i,0,K) ans=min(ans,f[1][1][i]);
	printf("%d\n",ans);
}