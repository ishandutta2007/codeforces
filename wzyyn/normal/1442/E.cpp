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
int n,a[N];
vector<int> e[N];
int q[2][N],vis[N];
int deg[N];
int Q(int c1,int c2){
	For(i,1,n) vis[i]=0;
	For(i,1,n) deg[i]=e[i].size();
	int h[2],t[2];
	h[0]=t[0]=h[1]=t[1]=0;
	For(i,1,n)
		if (deg[i]<=1){
			if (a[i]==c2)
				q[1][++t[1]]=i;
			else
				q[0][++t[0]]=i;
			vis[i]=1;
		}
	For(i,1,n){
		int p1=(i&1)^1,p2=p1^1;
		while (h[p1]!=t[p1]){
			int x=q[p1][++h[p1]];
			for (auto i:e[x])
				if (!vis[i]&&(--deg[i])<=1){
					vis[i]=1;
					if (a[i]==0||a[i]==(p1?c2:c1))
						q[p1][++t[p1]]=i;
					else q[p2][++t[p2]]=i;
				}
		}
		h[p1]=t[p1]=0;
		if (!t[p2]) return i;
	}
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	printf("%d\n",min(Q(1,2),Q(2,1))); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}