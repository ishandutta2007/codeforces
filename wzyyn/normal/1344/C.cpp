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
int n,m,deg[N];
vector<int> e[N];
int q[N],f1[N],f2[N];
void topo_sort(){
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (!--deg[i])
				q[++t]=i;
	}
	if (t!=n){
		puts("-1");
		exit(0);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); ++deg[y];
	}
	topo_sort();
	For(i,1,n) f1[i]=f2[i]=i;
	For(i,1,n) for (auto j:e[q[i]])
		f1[j]=min(f1[j],f1[q[i]]);
	Rep(i,n,1) for (auto j:e[q[i]])
		f2[q[i]]=min(f2[q[i]],f2[j]);
	int ans=0;
	For(i,1,n) ans+=(f1[i]==i&&f2[i]==i);
	printf("%d\n",ans);
	For(i,1,n) putchar(f1[i]==i&&f2[i]==i?'A':'E');
}
/*

forall
forallforallexist
*/