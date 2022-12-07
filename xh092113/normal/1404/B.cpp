#include<bits/stdc++.h>



using namespace std;



#define rg register

#define In inline

#define ll long long

const int N = 1e5;
const int inf = 0x3f3f3f3f;



namespace IO{

    In int read(){

        int s = 0,ww = 1;

        char ch = getchar();

        while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}

        while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}

        return s * ww;

    }
    In void write(int x){
    	if(x < 0)x = -x,putchar('-');
    	if(x > 9)write(x / 10);
    	putchar('0' + x % 10);
    }

};
using namespace IO;

int n,m,ua,ub,da,db;
vector<int> E[N+5];
int dep[N+5],fa[N+5][20];

void prepro(int u,int f){
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for(rg int i = 0;i < E[u].size();i++){
		int v = E[u][i];
		if(v == f)continue;
		prepro(v,u);
	}
}

int getdis(int u,int v){
	int lca,x = u,y = v;
	if(dep[x] < dep[y])swap(x,y);
	for(rg int i = 18;i >= 0;i--)if(dep[x] - (1<<i) >= dep[y])x = fa[x][i];
	if(x == y)lca = x;
	else{
		for(rg int i = 18;i >= 0;i--)if(fa[x][i] != fa[y][i])x = fa[x][i],y = fa[y][i];
		lca = fa[x][0];
	}
	return dep[u] + dep[v] - 2 * dep[lca];
}

queue<int>q;
int dis[N+5];
pair<int,int> bfs(int u){
	memset(dis,0x3f,sizeof(dis));
	dis[u] = 0;
	int ans = 0,vi;
	q.push(u);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(rg int i = 0;i < E[u].size();i++){
			int v = E[u][i];
			if(dis[v] != inf)continue;
			dis[v] = dis[u] + 1;
			if(dis[v] > ans)ans = dis[v],vi = v;
			q.push(v);
		}
	}
	return make_pair(ans,vi);
}

int getd(){
	int u = bfs(1).second;
	return bfs(u).first;
}

bool solve(){
//cout<<"solve1"<<endl;
	n = read(),ua = read(),ub = read(),da = read(),db = read();
//cout<<"n="<<n<<" ua="<<ua<<" ub="<<ub<<" da="<<da<<" db="<<db<<endl;
	for(rg int i = 1;i <= n;i++)E[i].resize(0);
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		E[u].push_back(v);
		E[v].push_back(u);
	}
//cout<<"solve2"<<endl;
	prepro(1,0);
	for(rg int j = 1;j <= 18;j++)
		for(rg int i = 1;i <= n;i++)fa[i][j] = fa[fa[i][j-1]][j-1];
//for(rg int i = 1;i <= n;i++)cout<<"i="<<i<<" dep="<<dep[i]<<" fa0="<<fa[i][0]<<" fa1="<<fa[i][1]<<endl;
//cout<<getd()<<endl;
	if(2 * da >= db)return 1;
	if(getdis(ua,ub) <= da)return 1;
//cout<<"solve3"<<endl;
	if(getd() <= 2 * da)return 1;
//cout<<"solve4"<<endl;
	return 0;	
}



int main(){

//	freopen("CF1404B.in","r",stdin);
//	freopen("CF1404B.out","w",stdout);
	
	int T = read();
	while(T--){
		if(solve())puts("Alice");
		else puts("Bob");
	}
	
	return 0;

}