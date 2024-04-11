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
const int N=5005;
int n,m,x[N],y[N];
int deg[N],q[N];
vector<int> e[N];
bool DAG(){
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (!--deg[i])
				q[++t]=i;
	}
	return t==n;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		e[x[i]].PB(y[i]);
		++deg[y[i]];
	}
	if (DAG()){
		printf("1\n");
		For(i,1,m) printf("1 ");
	}
	else{
		printf("2\n");
		For(i,1,m) printf("%d ",x[i]<y[i]?1:2);
	}
}