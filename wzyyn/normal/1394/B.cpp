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
const int N=200005;
int n,m,k,ans;
vector<pii> e[N];
ull hsh[N],S;
ull sum[10][10];
ull rnd(){
	ull s=0;
	For(i,1,6) s=s*16+rand()%16;
	return s;
}
void dfs(int x,ull v){
	if (x>k){
		ans+=(S==v);
		return;
	}
	For(i,0,x-1)
		dfs(x+1,v^sum[x][i]);
}
int main(){
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].PB(pii(v,y));
	}
	For(i,1,n)
		hsh[i]=rnd(),S^=hsh[i];
	For(i,1,n){
		sort(e[i].begin(),e[i].end());
		For(j,0,e[i].size()-1)
			sum[e[i].size()][j]^=hsh[e[i][j].se];
	}
	dfs(1,0);
	cout<<ans<<endl;
}