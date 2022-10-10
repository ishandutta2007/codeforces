// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int N,M;
vector< vector<int> > par,son,val;
vector< pair<int,int> > I;
vector<int> dep;
	
void DFS(int R) {
	if(I[R].ss != -1) return;
	I[R].ss =I[R].ff+1;
	ALL_THE(son[R],it) {
		I[*it].ff =I[R].ss;
		dep[*it] =dep[R]+1;
		DFS(*it);
		I[R].ss =I[*it].ss;}
	}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
   	par.resize(20,vector<int>(N+1,N));
	val.resize(20,vector<int>(N+1,M+tisic));
	son.resize(N+1);
	I.resize(N+1);
	dep.resize(N+1,0);
	vector< pair<int,int> > D;
	vector< vector< pair<int,int> > > Q(M);
	for(int i =0; i < M; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int x,y;
			cin >> x >> y;
			par[0][--x] =--y;
			son[y].push_back(x);
			val[0][x] =i;}
		if(t == 2) {
			int x; cin >> x;
			D.push_back(make_pair(--x,i));}
		if(t == 3) {
			int x,y; 
			cin >> x >> y;
			Q[--y].push_back(make_pair(--x,i));}
		}
	
	for(int i =1; i < 20; i++) for(int j =0; j <= N; j++) {
		par[i][j] =par[i-1][par[i-1][j]];
		val[i][j] =max(val[i-1][j],val[i-1][par[i-1][j]]);}
	I[N].ff =0;
	for(int i =0; i <= N; i++) I[i].ss =-1;
	for(int i =0; i < N; i++) if(par[0][i] == N) son[N].push_back(i);
	DFS(N);

	vector<int> ans(M,-1);
	for(int i =0; i < M; i++) ALL_THE(Q[i],it) {
		if(I[it->ff].ff > I[D[i].ff].ff || I[it->ff].ss <= I[D[i].ff].ff) {
			ans[it->ss] =0;
			continue;}
		// max. z cesty D[i].ff->it.ff
		int v =-1, k =0, a =D[i].ff;
		while(k >= 0 && par[k][a] != a) {
			if(dep[par[k][a]] < dep[it->ff]) {k--; continue;}
			v =max(v,val[k][a]);
			a =par[k][a];}
		if(v < D[i].ss) ans[it->ss] =1;
		else ans[it->ss] =0;}
	
	for(int i =0; i < M; i++) if(ans[i] >= 0)
		cout << ((ans[i] == 1)?"YES\n":"NO\n");
    return 0;}
        
// look at my code
// my code is amazing