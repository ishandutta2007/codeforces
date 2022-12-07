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
const int mo[]={998244353,1000000009};
const int N=35,M=100005;
int id[N][M];
int v[N][2][M],P[2][M];
int n,nd,L[N],q[M],deg[M];
vector<int> e[M];
char s[M];
bool same(int i,int j,int si,int sj,int l){
	For(f,0,1){
		int vi=(v[i][f][si+l-1]+mo[f]-v[i][f][si-1])%mo[f];
		int vj=(v[j][f][sj+l-1]+mo[f]-v[j][f][sj-1])%mo[f];
		if (si<=sj) vi=1ll*vi*P[f][sj-si]%mo[f];
		else vj=1ll*vj*P[f][si-sj]%mo[f];
		if (vi!=vj) return 0;
	}
	return 1;
}
void add(int x,int y){
	e[x].PB(y); ++deg[y];
}
bool topo(){
	int t=0;
	For(i,1,nd) if (!deg[i]) q[++t]=i;
	For(i,1,t) for (auto j:e[q[i]])
		if (!--deg[j]) q[++t]=j;
	return t==nd;
}
bool check(int l,int r){
	nd=1;
	For(i,l,r) For(j,1,L[i]) id[i][j]=++nd;
	For(i,l,r) id[i][L[i]+1]=1;
	For(i,1,nd) deg[i]=0,e[i].resize(0);
	For(i,l,r) For(j,1,L[i]) For(k,l,r){
		if (j==1&&L[k]==L[i]) continue;
		int len=min(L[i]-j+1,L[k]);
		if (same(i,k,j,1,len))
			add(id[i][j],id[i][j+len]+id[k][1+len]-1);
	}
	For(i,l,r) add(1,id[i][1]);
	return topo();
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		L[i]=strlen(s+1);
		For(f,0,1){
			P[f][0]=1;
			For(j,1,L[i]){
				P[f][j]=1ll*P[f][j-1]*233%mo[f];
				v[i][f][j]=(v[i][f][j-1]+1ll*P[f][j]*s[j])%mo[f];
			}
		}
	}
	int j=1,ans=0;
	For(i,1,n){
		for (;j<=n&&check(i,j);++j);
		//cout<<i<<' '<<j<<endl;
		ans+=j-i;
	}
	printf("%d\n",ans);
}