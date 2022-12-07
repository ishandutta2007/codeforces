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
int a[N],q[N],n,T;
vector<int> e[N];
void dfs(int x){
	q[x]=T--;
	Rep(i,e[x].size()-1,0)
		dfs(e[x][i]);
}
void solve(){
	scanf("%d",&n); T=n+1;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n+1) e[i].clear();
	int top=1,flag=1;
	q[top]=n+1;
	Rep(i,n,1)
		if (a[i]==-1){
			e[q[top]].PB(i);
			q[++top]=i;
		}
		else{
			for (;top&&q[top]!=a[i];top--);
			if (q[top]!=a[i]){
				flag=0;
				break;
			}
			e[a[i]].PB(i);
			q[++top]=i;
		}
	if (!flag){
		puts("-1");
		return;
	}
	dfs(n+1);
	For(i,1,n) printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}