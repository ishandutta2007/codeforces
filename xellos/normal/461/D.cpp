// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

long long ans =1;
int K;
vector< vector< pair<int,int> > > G[2];
vector<bool> vis;
vector<int> x;

void DFS(int k, int R) {
	if(vis[R]) return;
	vis[R] =true;
	ALL_THE(G[k][R],it) {
		if(vis[it->ff]) {
			if(x[R]^x[it->ff]^(it->ss)) ans =0;}
		else {
			x[it->ff] =x[R]^it->ss;
			K--;
			DFS(k,it->ff);}
		}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M,N;
	cin >> M >> N;
	for(int i =0; i < 2; i++) G[i].resize(M+tisic);
	for(int i =0; i < N; i++) {
		int x,y;
		string s;
		cin >> x >> y >> s;
		x--, y--;
		if(x < y) swap(x,y);
		if(x+y >= M) {
			int z =y;
			y =M-1-x;
			x =M-1-z;}
//		cout << (x+y)%2 << " " << (x-y)/2 << " " << (x+y)/2+1 << " " << int(s[0] == 'o') << "\n";
		G[(x+y)%2][(x-y)/2].push_back(make_pair((x+y)/2+1,int(s[0] == 'o')));
		G[(x+y)%2][(x+y)/2+1].push_back(make_pair((x-y)/2,int(s[0] == 'o')));}

	K =M;
	ans =1;
	x.resize(M+tisic,0);
	for(int k =0; k < 2; k++) {
		vis.clear();
		vis.resize(M+tisic,false);
		for(int i =0; i < M+tisic; i++) {
			x[i] =0;
			DFS(k,i);}
		}

	long long mod =1000000007;
	for(int i =0; i < K; i++) {
		ans *=2;
		if(ans >= mod) ans -=mod;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing