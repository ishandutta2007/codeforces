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
#define double long double
using namespace std;
const int N=500005;
int n,m;
vector<int> e[N];
int co[N],id[N],vis[N];
bool cmp(int x,int y){
	return co[x]<co[y];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n)
		scanf("%d",&co[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n){
		for (auto j:e[i])
			vis[co[j]]=i;
		For(j,1,co[i]-1)
			if (vis[j]!=i)
				return puts("-1"),0;
		if (vis[co[i]]==i)
			return puts("-1"),0;
	}
	For(i,1,n) cout<<id[i]<<' ';
}