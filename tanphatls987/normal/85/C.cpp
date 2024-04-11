#include <bits/stdc++.h>

using namespace std;

#define FOR(i,L,R) for(auto i=L;i<=R;i++)
#define FORD(i,R,L) for(auto i=R;i>=L;i++)
#define REP(i,L,R) for(auto i=L;i<R;i++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll,int> lli;


const int N=1e5+10;
// --------------------------

int FMI[N],FMA[N],n,x,w[N],lv[N],st[N],q,top,ans[N];
ll f[N];
vector <int> a[N];
void DFS1(int x){
	FMI[x]=FMA[x]=w[x];
	for(auto y:a[x]){
		lv[y]=lv[x]+1;
		DFS1(y);
		FMI[x]=min(FMI[x],FMI[y]);
		FMA[x]=max(FMA[x],FMA[y]);
	}
}
void DFS2(int x,int L,int R){
	if (a[x].empty()){
		ans[++top]=x;
		st[top]=L;
		return;
	}
	int j=(w[a[x][1]]<w[a[x][0]]);
	f[a[x][j]]=f[x]+FMI[a[x][1-j]];
	f[a[x][1-j]]=f[x]+FMA[a[x][j]];
	DFS2(a[x][j],L,w[x]);
	DFS2(a[x][1-j],w[x],R);
}
int main() {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d%d",&x,w+i);
		if (x==-1) x++;
		a[x].push_back(i);
	}
	lv[a[0][0]]=1;
	DFS1(a[0][0]);
	DFS2(a[0][0],*min_element(w+1,w+n+1),*max_element(w+1,w+n+1));
	//cout<<top<<'\n';
	//FOR(i,1,top) printf("%d %d\n",ans[i],st[i]);
	//FOR(i,1,n) printf("%d %lld %d %d\n",lv[i],f[i],FMI[i],FMA[i]);
	scanf("%d",&q);
	//for(auto i:ans) printf("%d %lld\n",i.X,i.Y);
	while (q--){
		scanf("%d",&x);
		int L=1,R=top;
		while (L<=R){
			int M=(L+R)/2;
			if (x>st[M]) L=M+1;
			else R=M-1;
		}
		R+=(R==0);
		printf("%.9f\n",(f[ans[R]]+.0)/(lv[ans[R]]-1));
	}
	return 0;
}