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
const int N=105;
int fa[N],f[N];
__int128 v[N],P[N];
vector<int> e[N];
int vis[N],n;
void dfs(int x,int fa){
	::fa[x]=fa;
	for (auto i:e[x])
		if (i!=fa) dfs(i,x);
	v[x]=P[n]-1;
	Rep(i,n-1,0){
		v[x]^=P[i];
		priority_queue<__int128> Q;
		for (auto j:e[x]) if (j!=fa) Q.push(v[j]);
		bool flag=1;
		Rep(j,n-1,0)
			if (v[x]&P[j]){
				if (!Q.empty()){
					__int128 tmp=Q.top(); Q.pop();
					if (tmp/P[j]>1) flag=0;
					if (tmp&P[j]) Q.push(tmp-P[j]);
				}
			}
			else
				if (!Q.empty())
					if (Q.top()>=P[j])
						flag=0;
		if (!Q.empty()) flag=0;
		if (flag==0) v[x]^=P[i];
	}
	priority_queue<pair<__int128,int> > Q2;
	for (auto i:e[x]) if (i!=fa) Q2.push(make_pair(v[i],i));
	Rep(i,n-1,0)
		if (v[x]&P[i]){
			//v[x]^=P[i];
			pair<__int128,int> tmp=Q2.top();
			Q2.pop();
			if (tmp.fi&P[i]){
				tmp.fi^=P[i];
				Q2.push(tmp);
			}
			else
				f[tmp.se]=i;
		}
	//cout<<x<<' '<<(int)v[x]<<endl;
}
void Del(int x,int fa){
	if (vis[x]) return;
	vis[x]=1;
	for (auto i:e[x]) if (i!=fa) Del(i,x);
}
int main(){
	scanf("%d",&n);
	P[0]=(__int128)(1);
	For(i,1,n) P[i]=P[i-1]<<(__int128)1;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	for (;;){
		int p=0;
		For(i,2,n)
			if (!vis[i]&&!vis[fa[i]])
				if (!p||(f[i]>f[p])) p=i;
		if (!p){
			For(i,1,n)
				if (!vis[i]){
					cout<<"! "<<i<<endl;
					exit(0);
				}
		}
		cout<<"? "<<p<<' '<<fa[p]<<endl;
		int x; cin>>x;
		Del(p+fa[p]-x,x);
	}
}