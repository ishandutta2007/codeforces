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

const int inf = 1e9;

struct way{
	int to,flow,rev;
};

const int N = 1010;
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

int n,m;
dinic A;
int x1[100],y1[100],x2[100],y2[100];
int edg[110][110];
int main(){
	read(n,m);
	
	vector<int> X,Y;
	for(int i=0;i<m;i++){
		read(x1[i],y1[i],x2[i],y2[i]);
		X.push_back(x1[i]);
		Y.push_back(y1[i]);
		X.push_back(x2[i]+1);
		Y.push_back(y2[i]+1);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	dinic A;
	for(int i=0;i<m;i++){
		int lx = lower_bound(X.begin(),X.end(),x1[i])-X.begin(),rx = lower_bound(X.begin(),X.end(),x2[i]+1)-X.begin();
		int ly = lower_bound(Y.begin(),Y.end(),y1[i])-Y.begin(),ry = lower_bound(Y.begin(),Y.end(),y2[i]+1)-Y.begin();
		for(int j=lx;j<rx;j++)for(int k=ly;k<ry;k++)edg[j][k] = 1;
	}
	for(int i=0;i<(int)X.size()-1;i++) A.addedge(A.s,i,X[i+1]-X[i]);
	for(int i=0;i<(int)Y.size()-1;i++) A.addedge(i+200,A.t,Y[i+1]-Y[i]);
	for(int i=0;i<(int)X.size()-1;i++){
		for(int j=0;j<(int)Y.size()-1;j++){
			if(edg[i][j]){
				A.addedge(i,j+200,inf);
			}
		}
	}
	cout<<A.getans()<<endl;
	return 0;
}