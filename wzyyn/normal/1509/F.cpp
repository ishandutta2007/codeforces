#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;


const int N=200005;
const int NN=655;

int n,m;
namespace solver1{
	int e[NN][NN],S;
	int vi[NN],d[NN];
	ll Func(){
		ll S=0;
		For(i,1,n) d[i]=3<<29,vi[i]=0;
		d[1]=0;
		For(i,1,n){
			int p=-1;
			For(j,1,n)
				if (!vi[j]&&(p==-1||d[p]>d[j]))
					p=j;
			vi[p]=1; S+=d[p];
			For(j,1,n)
				if (e[p][j]<d[j]&&!vi[j])
					d[j]=e[p][j];
		}
		return S;
	}
	void solve(){
		ll ans=1ll<<60;
		For(i,1,m){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			e[x][y]=e[y][x]=v; S^=v;
		}
		For(i,1,n) For(j,i+1,n)
			if (!e[i][j]){
				e[i][j]=e[j][i]=S;
				ans=min(ans,Func());
				e[i][j]=e[j][i]=0;
			}
		cout<<ans<<endl;
	}
}


struct Edge{
	int x,y,v;
	bool operator <(const Edge &a)const{
		return v<a.v;
	}
};
namespace solver2{
	vector<int> e[N];
	Edge E[N];
	int q[N],Q[N],fa[N],vi[N],vis[N];
	
	int get(int x){
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	void work(int p){
		int h=0,t=1; Q[1]=p;
		while (h!=t){
			int x=Q[++h]; vi[x]=1; fa[x]=p;
			for (auto i:e[x]) vis[i]=1;
			int top=0;
			For(i,1,*q)
				if (vi[q[i]]);
				else if (vis[q[i]]) q[++top]=q[i];
				else Q[++t]=q[i],vi[q[i]]=1;
			*q=top;
			for (auto i:e[x]) vis[i]=0;
		}
	}
	void solve(){
		For(i,1,m){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			E[i]=(Edge){x,y,v};
			e[x].PB(y); e[y].PB(x);
		}
		*q=0;
		For(i,1,n) q[++*q]=i;
		For(i,1,n) fa[i]=i;
		For(i,1,n) if (!vi[i]) work(i);
		sort(E+1,E+m+1);
		
		ll S=0;
		For(i,1,m){
			int x=get(E[i].x);
			int y=get(E[i].y);
			if (x!=y){
				fa[x]=y;
				S+=E[i].v;
			}
		}
		cout<<S<<endl;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if (m+n>=1ll*n*(n-1)/2)
		solver1::solve();
	else solver2::solve();
}