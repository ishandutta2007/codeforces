#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1e6+5;

int dep[maxn];
int pa[maxn][21];
int nh,n,m;
bool p[maxn];
vector<int> e[maxn];
queue<int> q;

void build(){
    q.push(n);
    dep[n]=1;
    int u,s;
    while(!q.empty()){
        s=q.front();
        q.pop();

        for (int i = 1; i <= 20; ++i)
            pa[s][i]=pa[pa[s][i-1]][i-1];

		for(int i=0;i<e[s].size();++i){
            u=e[s][i];
            if(dep[u])continue;
            pa[u][0]=s;
            dep[u]=dep[s]+1;
            q.push(u);
		}
    }
}

void cross(int s,int v){
	p[s]=1;
	s=pa[s][0];
	while(dep[s]>=v&&!p[s]){
		p[s]=1;
		s=pa[s][0];
	}
}

int climb(int s,int v){
	int r=s;
	for(int i=20;i>=0;--i){
		if(!p[pa[s][i]]&&dep[pa[s][i]]>=v)
			s=pa[s][i];
	}
	return dep[r]-dep[s]+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int k;
	cin>>n>>k;
	k=n-k;
	int x,y;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	build();
	--k;
	int v,tp;
	p[n]=true;
	for(int i=n-1;i>0;--i){
		if(p[i])continue;
		tp=climb(i,1);
		if(tp<=k){
			k-=tp;
			cross(i,1);
		}
	}
	for(int i=1;i<=n;++i)if(!p[i])cout<<i<<' ';
	return 0;
}