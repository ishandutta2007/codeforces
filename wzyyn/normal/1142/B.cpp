#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,m,Q;
int p[N],nxt[N],las[N];
int a[N],b[N],mn[N],q[N];
vector<int> e[N];
void dfs(int x,int d){
	q[d]=x;
	mn[x]=(d<n?m+1:q[d-n+1]);
	for (auto i:e[x]) dfs(i,d+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) nxt[p[i]]=p[i==n?1:i+1];
	For(i,1,m) scanf("%d",&b[i]);
	For(i,1,n) las[i]=m+1;
	Rep(i,m,1){
		e[las[nxt[b[i]]]].PB(i);
		las[b[i]]=i;
	}
	dfs(m+1,1);
	Rep(i,m-1,1) mn[i]=min(mn[i],mn[i+1]);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d",mn[l]<=r?1:0);
	}
}