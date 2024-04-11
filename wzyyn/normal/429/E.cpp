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
pii q[N];
vector<int> e[N];
int n,top,vis[N];
void dfs(int x,int c){
	if (vis[x]!=-1) return;
	vis[x]=c;
	for (auto i:e[x]) dfs(i,!c);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[2*i-1].PB(2*i);
		e[2*i].PB(2*i-1);
		q[++top]=pii(x*2,2*i-1);
		q[++top]=pii(y*2+1,2*i);
	}
	sort(q+1,q+top+1);
	For(i,1,n){
		//cout<<q[2*i-1].se<<' '<<q[2*i].se<<endl;
		e[q[2*i-1].se].PB(q[2*i].se);
		e[q[2*i].se].PB(q[2*i-1].se);
	}
	For(i,1,2*n) vis[i]=-1;
	For(i,1,2*n) if (vis[i]==-1) dfs(i,0);
	For(i,1,n) printf("%d ",vis[i*2-1]);
}