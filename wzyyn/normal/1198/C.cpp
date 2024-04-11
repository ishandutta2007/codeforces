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
const int N=500005;
int vis[N],q[N],n,m;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); *q=0;
		For(i,1,3*n) vis[i]=0;
		For(i,1,m){
			int x,y;
			scanf("%d%d",&x,&y);
			if (!vis[x]&&!vis[y]){
				vis[x]=vis[y]=1;
				q[++*q]=i;
			}
		}
		if (*q>=n){
			puts("Matching");
			For(i,1,n) printf("%d ",q[i]);
			puts("");
		}
		else{
			puts("IndSet");
			int res=n;
			For(i,1,3*n)
				if (!vis[i]&&res)
					printf("%d ",i),--res;
			puts("");
		}
	}
}