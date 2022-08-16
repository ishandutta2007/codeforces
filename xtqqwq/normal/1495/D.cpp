#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
int c[405][405],maxa[405];
vector<int> d[405][405],adj[405];
bool vis[405];

int main(){
	n=readint(); m=readint();
	memset(c,0x3f,sizeof(c));
	for(int i=1;i<=n;i++) c[i][i]=0;
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y),adj[y].pb(x);
		c[x][y]=c[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(c[i][j],c[i][k]+c[k][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n;k++) maxa[k]=0;
			for(int k=1;k<=n;k++){
				int tmp=(c[k][j]-c[k][i]+c[i][j])/2;
				d[tmp][(c[k][j]+c[k][i]-c[i][j])/2].pb(k);
				chkmax(maxa[tmp],(c[k][j]+c[k][i]-c[i][j])/2);
			}
			bool fl=0;
			ll ans=1;
			for(int k=0;k<=c[i][j];k++){
				if(d[k][0].size()!=1){
					ans=0,fl=1;
					break;
				}
				for(int l=1;l<=maxa[k];l++){
					if(!d[k][l].size()){
						ans=0,fl=1;
						break;
					}
					for(auto r:d[k][l-1]) vis[r]=1;
					for(auto r:d[k][l]){
						int sum=0;
						for(auto s:adj[r]) sum+=vis[s];
						ans=ans*sum%cys;
					}
					for(auto r:d[k][l-1]) vis[r]=0;
				}
				if(fl) break;
			}
			printf("%lld ",ans);
			for(int k=1;k<=n;k++) d[(c[k][j]-c[k][i]+c[i][j])/2][(c[k][j]+c[k][i]-c[i][j])/2].clear();
		}
		printf("\n");
	}
	return 0;
}