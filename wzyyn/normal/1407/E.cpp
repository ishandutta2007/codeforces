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
const int N=1000005;
vector<pii> E[N];
int n,m,q[N],col[N];
int f[N],inq[N],vi[N][2];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		//e[x].PB(pii(y,v));
		E[y].PB(pii(x,v));
	}
	int h=0,t=1;
	For(i,1,n) f[i]=-1;
	q[1]=n; inq[n]=1; f[n]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:E[x]){
			vi[i.fi][i.se]=1;
			if (vi[i.fi][0]&&vi[i.fi][1])
				if (!inq[i.fi]){
					inq[i.fi]=1;
					col[i.fi]=i.se;
					f[i.fi]=f[x]+1;
					q[++t]=i.fi;
				}
		}
	}
	For(i,1,n) if (!inq[i])
		col[i]=(vi[i][0]?1:0);
	printf("%d\n",f[1]);
	For(i,1,n) printf("%d",col[i]);
	
}