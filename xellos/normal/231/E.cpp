// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;
using namespace std::tr1;

int N,M,a,b,c,d;
vector< vector<int> > adjL;
vector< vector<int> > cy;
vector<bool> isS;
vector<int> akyC;
vector<int> ako;
vector<int> vis;
	
void dfs(int R) {
	vis[R] =true;
	for(int i =0; i < (signed)adjL[R].size(); i++) {
		a =adjL[R][i];
		if(a == ako[R]) continue;
		if(isS[a] && akyC[a] == -1) {
			b =cy.size();
			cy.resize(b+1);
			cy[b].push_back(R);
			b =R;
			akyC[R] =cy.size()-1;
			while(b != a) {
				b =ako[b];
				if(b < 0) break;
				cy[cy.size()-1].push_back(b);
				akyC[b] =cy.size()-1;}}
		else if(!vis[a]) {
			ako[a] =R;
			isS[a] =true;
			dfs(a);
			a =adjL[R][i];
			isS[a] =false;}}
	return;}

int main() {
	int N,M,a,b;
	scanf(" %d %d",&N,&M);
	adjL.resize(N);
	for(int i =0; i < M; i++) {
		scanf(" %d %d",&a,&b);
		adjL[a-1].push_back(b-1);
		adjL[b-1].push_back(a-1);}

	// zisti cykly
	isS.resize(N,false);
	ako.resize(N,-1);
	akyC.resize(N,-1);
	vis.resize(N,false);
	isS[0] =true;
	dfs(0);
	
	// prerob na strom
	a =cy.size();
	for(int i =0; i < N; i++) if(akyC[i] == -1) {
		akyC[i] =a;
		a++;}
	vector<int> par(a,-1);
	vector< vector<int> > son(N);
	for(int i =0; i < N; i++) for(int j =0; j < (signed)adjL[i].size(); j++)
		if(akyC[adjL[i][j]] != akyC[i] && ako[i] == adjL[i][j]) {
			par[akyC[i]] =akyC[adjL[i][j]];
			son[akyC[adjL[i][j]]].push_back(akyC[i]);}
	b =cy.size();
	
	// LCA init
	vector< vector<int> > nad(a);
	vector<int> S(a,0);
	for(int i =0; i < a; i++) nad[i].resize(20,akyC[0]);
	queue<int> q;
	q.push(akyC[0]);
	vector<int> dep(a,0);
	if(akyC[0] < b) S[akyC[0]] =1;
	while(!q.empty()) {
		for(int i =0; i < (signed)son[q.front()].size(); i++) {
			c =son[q.front()][i];
			S[c] =S[q.front()]+(int)(c < b);
			dep[c] =dep[q.front()]+1;
			nad[c][0] =q.front();
			for(int j =0; j < 19; j++) nad[c][j+1] =nad[nad[c][j]][j];
			q.push(c);}
		q.pop();}
	
	// LCA
	int Q;
	scanf(" %d",&Q);
	for(int q =0; q < Q; q++) {
		scanf(" %d %d",&c,&d);
		c =akyC[c-1], d =akyC[d-1];
		int poc2 =S[c]+S[d];
		if(dep[c] < dep[d]) swap(c,d);
		int i =19;
		while(dep[c] > dep[d]) {
			if(dep[nad[c][i]] < dep[d]) i--;
			else c =nad[c][i];}
		i =19;
		while(i >= 0) {
			if(nad[c][i] == nad[d][i]) i--;
			else {
				c =nad[c][i];
				d =nad[d][i];}}
		if(c != d) {
			c =par[c];
			d =par[d];}
		poc2 -=S[c]*2-(int)(c < b);
		
		long long ans =1;
		vector<int> v;
		int m =poc2;
		while(m > 0) {
			v.push_back(m%2);
			m /=2;}
		while(!v.empty()) {
			ans =(ans*ans)%1000000007;
			if(ans < 0) ans +=1000000007;
			if(v[v.size()-1] == 1) ans =(ans*2)%1000000007;
			if(ans < 0) ans +=1000000007;
			v.pop_back();}
		printf("%I64d\n",ans);}
	
	return 0;}
        
// look at my code
// my code is amazings