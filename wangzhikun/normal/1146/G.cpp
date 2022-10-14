#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define y1 y_1
#define y2 y_2
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

const int inf = 10000;

struct way{
	int to,flow,rev;
};

const int N = 20010;
struct dinic{
	vector<way> ways[N];
	int n,m,s,t,u,v,f,ans = 0,cuad,cur,cpo[N];
	int depth[N] = {0};
	queue<int> que;
	dinic(){
		s = N-1;
		t = N-2;
	}
	bool bfs(){
		memset(depth,0,sizeof(depth));
		depth[s] = 1;
		que.push(s);
		while(!que.empty()){
			cur = que.front(); que.pop();
			for(auto ech:ways[cur])
				if(!depth[ech.to]&&ech.flow>0){
					depth[ech.to] = depth[cur]+1;
					que.push(ech.to);
				}
		}
		return depth[t]!=0;
	}
	int dfs(int num,int flow){
		if(num == t) return flow;
		int cacu = 0;
		for(int &i=cpo[num];i<ways[num].size();i++){
			way cw = ways[num][i];
			if(depth[cw.to]!=depth[num]+1)continue;
			int able = dfs(cw.to,min(flow,cw.flow));
			if(able>0){
				flow-=able;
				ways[num][i].flow-=able;
				ways[cw.to][cw.rev].flow+=able;
				cacu+=able;
			}
			if(flow == 0)break;
		}
		return cacu;
	}
	void addedge(int u,int v,int f){
		ways[u].push_back((way){v,f,(int)ways[v].size()});
		ways[v].push_back((way){u,0,(int)ways[u].size()-1});
	}
	int getans(){
		while(bfs()){
			memset(cpo,0,sizeof(cpo));
			while(1){
				cuad = dfs(s,inf);
				if(cuad == 0)break;
				ans+=cuad;
			}
		}
		return ans;
	}
};

int n,h,m,l,r,x,c;
dinic A;
int id(int i,int j){
	return i*(h+10)+j;
}
int main(){
	read(n,h,m);
	int ans = n*h*h;
	for(int i=1;i<=n;i++){
		A.addedge(A.s,id(i,0),h*h);
		for(int j=1;j<=h;j++){
			A.addedge(id(i,j-1),id(i,j),h*h-j*j);
		}
	}
	for(int i=1;i<=m;i++){
		read(l,r,x,c);
		for(int j=l;j<=r;j++){
			A.addedge(id(j,x),i+5000,inf);
		}
		A.addedge(i+5000,A.t,c);
	}
	cout<<ans-A.getans()<<endl;
	return 0;
}