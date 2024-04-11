#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 200000 + 100;

int N, M;
struct LINE{
	int a, b;
}lines[MN];

vector<pii> con[MN];

int p[2*MN];
int par(int n){
	if(p[n] == n) return n;
	p[n] = par(p[n]);
	return p[n];
}
void merge(int a,int b){
	int p1=par(a), p2=par(b);
	p[p1] = p2;
}
struct POWER{
	int a=-1, b=-1, c=-1;
	void update(int n){
		if(a<n){
			c=b;
			b=a;
			a=n;
		}
		else if(b<n){
			c=b;
			b=n;
		}
		else if(c<n){
			c=n;
		}
	}
	bool operator <(POWER A)const{
		if(a!=A.a) return a<A.a;
		if(b!=A.b) return b<A.b;
		return c<A.c;
	}
}data[2*MN];

int zip[2*MN];
int dead[MN], ans[MN];
int V[MN];
int sz[MN], tsz;
vector<int> E[MN];

vector<int> members;
void dfs2(int n, int depth){
	V[n] = depth;
	sz[n] = 1;
	tsz++;
	members.push_back(n);
	for(int t: E[n])if(V[t] != depth && !dead[t]){
		dfs2(t, depth);
		sz[n] += sz[t];
	}
}

void dfs(int n, int depth){
	tsz = 0;
	members.clear();
	dfs2(n, depth);
	int p = members[0], minv = 1e9;
	for(int member: members){
		if(tsz - sz[member] <= tsz/2){
			if(minv > sz[member]){
				minv = sz[member];
				p = member;
			}
		}
	}
	dead[p] = 1;
	ans[p] = depth;
	for(int t: E[p])if(!dead[t]){
		dfs(t, depth+1);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0;i<M;i++){
		II(a)II(b); a--, b--;
		lines[i] = {a, b};
	}
	for(int i=0;i<N;i++){
		lines[i+M] = {i, (i+1)%N};
	}
	M += N;
	for(int i=0;i<M;i++){
		con[lines[i].a].emplace_back(lines[i].b, 2*i);
		con[lines[i].b].emplace_back(lines[i].a, 2*i+1);
	}
	for(int i=0;i<2*M;i++) p[i]=i;
	for(int i=0;i<N;i++){
		int l = (i+N-1)%N;
		int r = (i+1)%N;
		sort(all(con[i]));
		for(int j=0;j<con[i].size();j++){
			pii e1 = con[i][j], e2 = con[i][(j+1)%con[i].size()];
			if((e1.first == l && e2.first == r) || (e1.first == r && e2.first == l)){
			}
			merge(e1.second^1, e2.second);
		}
	}
	vector<int> kings;
	int ex = par(2*(M-N));
	for(int i=0;i<2*M;i++) if(par(i)==i && i != ex) kings.push_back(i);
	for(int i=0;i<M;i++){
		data[par(2*i)].update(lines[i].a);
		data[par(2*i+1)].update(lines[i].b);
	}
	sort(all(kings), [](int a,int b){
		return data[a] < data[b];
	});
	for(int i=0;i<kings.size();i++){
		zip[kings[i]] = i;
	}
	for(int i=0;i<M-N;i++){
		int l = zip[par(2*i)], r = zip[par(2*i+1)];
		E[l].push_back(r);
		E[r].push_back(l);
	}
	dfs(0, 1);
	for(int i=0;i<kings.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}