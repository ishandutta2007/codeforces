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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< pair<int,int> > E[100000+tisic];
	for(int i =0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		E[c].push_back(make_pair(--a,--b));}

	int B =300;

	vector< vector<int> > pairL(N),compH(M+1),G(N);
	vector<int> compA(N,-1),seq,CC,H;
	seq.dibs(N);
	CC.dibs(N);
	H.dibs(M);
	queue<int> q;
	for(int c =0; c <= M; c++) {
		int n =0, C =0;
		ALL_THE(E[c],it) {
			if(G[it->ff].empty()) n++;
			G[it->ff].push_back(it->ss);
			if(G[it->ss].empty()) n++;
			G[it->ss].push_back(it->ff);
			seq.push_back(it->ff);
			seq.push_back(it->ss);}

		ALL_THE(seq,it) if(compA[*it] == -1) {
			q.push(*it);
			compA[*it] =C;
			CC.push_back(*it);
			while(!q.empty()) {
				ALL_THE(G[q.front()],jt) if(compA[*jt] == -1) {
					compA[*jt] =C;
					CC.push_back(*jt);
					q.push(*jt);}
				q.pop();}
			if(n < B) 
				ALL_THE(CC,jt) ALL_THE(CC,kt) if(*jt != *kt) pairL[*jt].push_back(*kt);
			C++;
			CC.clear();}

		if(n >= B) {
			compH[c] =compA;
			H.push_back(c);}
		ALL_THE(seq,it) compA[*it] =-1, G[*it].clear();
		seq.clear();}

	vector< vector< pair<int,int> > > pairLn(N);
	for(int i =0; i < N; i++) {
		sort(begin(pairL[i]),end(pairL[i]));
		int a =0;
		while(a < pairL[i].size()) {
			int b =a;
			while(b < pairL[i].size() && pairL[i][a] == pairL[i][b]) b++;
			pairLn[i].push_back(make_pair(pairL[i][a],b-a));
			a =b;}
		}
	
	int Q;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		int a,b, ans =0;
		cin >> a >> b;
		a--, b--;
		ALL_THE(H,it) if(compH[*it][a] == compH[*it][b] && compH[*it][a] != -1) ans++;
//		ALL_THE(pairL[a],it) if(*it == b) ans++;
		if(!pairLn[a].empty() && pairLn[a][0].ff <= b) {
			int iA =0, iB =pairLn[a].size();
			while(iB-iA > 1) {
				int c =(iB+iA)/2;
				if(pairLn[a][c].ff <= b) iA =c;
				else iB =c;}
			if(pairLn[a][iA].ff == b) ans +=pairLn[a][iA].ss;
			}
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing