#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int N=150005;
int n[5],ban[N];
int v[5][N],f[N];
vector<int> e[N];
pii q[N];
int main(){
	For(i,1,4) scanf("%d",&n[i]);
	For(i,1,4) For(j,1,n[i]) scanf("%d",&v[i][j]);
	For(i,1,n[1]) f[i]=v[1][i];
	For(i,2,4){
		For(j,1,n[i]) e[j].resize(0);
		For(j,1,n[i-1]) q[j]=pii(f[j],j);
		sort(q+1,q+n[i-1]+1);
		int m,x,y;
		scanf("%d",&m);
		For(j,1,m){
			int x,y;
			scanf("%d%d",&x,&y);
			e[y].PB(x);
		}
		For(j,1,n[i]){
			for (auto k:e[j]) ban[k]=1;
			int p=1;
			for (;p<=n[i-1]&&ban[q[p].se];++p);
			if (p>n[i-1]) f[j]=1<<30;
			else f[j]=v[i][j]+q[p].fi;
			for (auto k:e[j]) ban[k]=0;
		}
	}
	int ans=1<<30;
	For(j,1,n[4]) ans=min(ans,f[j]);
	if (ans==1<<30) ans=-1;
	cout<<ans<<endl; 
}