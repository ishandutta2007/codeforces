#include <bits/stdc++.h>
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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > G[2];
	G[0].resize(N); G[1].resize(N);
	for(int i =0; i < M; i++) {
		int u,v;
		string s;
		cin >> u >> v >> s;
		int x =(s == "B")?0:1;
		G[x][--u].push_back(--v);
		G[x][v].push_back(u);}

	int ans =N+M+tisic;
	vector<int> ako;
	for(int k =0; k < 2; k++) {
		vector< vector<int> > Gid(N);
		vector< pair<int,int> > Edif;
		for(int i =0; i < N; i++) ALL_THE(G[k][i],it) {
			Gid[*it].push_back(i);
			Gid[i].push_back(*it);}
		for(int i =0; i < N; i++) ALL_THE(G[1-k][i],it) 
			Edif.push_back(make_pair(i,*it));
		queue<int> q;
		vector<int> comp(N,-1),sz;
		int C =0;
		vector< vector<int> > ccmp;
		for(int i =0; i < N; i++) if(comp[i] == -1) {
			q.push(i);
			comp[i] =C;
			int sza =1;
			vector<int> v(1,i);
			while(!q.empty()) {
				ALL_THE(Gid[q.front()],it) if(comp[*it] == -1) {
					comp[*it] =C;
					v.push_back(*it);
					sza++;
					q.push(*it);}
				q.pop();}
			sz.push_back(sza);
			ccmp.push_back(v);
			C++;}
		vector< vector<int> > G2(C);
		ALL_THE(Edif,it) G2[comp[it->ff]].push_back(comp[it->ss]);
		vector<int> col(C,-1);
		bool ok =true;
		int ansa =0;
		vector<int> akoa;
		for(int i =0; i < C; i++) if(col[i] == -1) {
			col[i] =0;
			q.push(i);
			int sz0 =sz[i], sz1 =0;
			vector<int> v0(1,i),v1;
			while(!q.empty()) {
				ALL_THE(G2[q.front()],it) {
					if(col[*it] == -1) {
						col[*it] =1-col[q.front()];
						if(col[*it] == 0) {sz0 +=sz[*it]; v0.push_back(*it);}
						else {sz1 +=sz[*it]; v1.push_back(*it);}
						q.push(*it);}
					else if(col[*it] == col[q.front()]) ok =false;}
				q.pop();}
			ansa +=min(sz0,sz1);
			if(sz0 <= sz1) ALL_THE(v0,it) ALL_THE(ccmp[*it],jt) akoa.push_back(*jt);
			else ALL_THE(v1,it) ALL_THE(ccmp[*it],jt) akoa.push_back(*jt);
			}
		if(!ok) continue;
		ans =min(ans,ansa);
		if(ansa == ans) ako =akoa;}

	if(ans == N+M+tisic) cout << "-1\n";
	else {
		cout << ans << "\n";
		ALL_THE(ako,it) cout << *it+1 << " ";
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing