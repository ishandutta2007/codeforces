// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

struct node {
	int son[26];
	int dep;
	node() {for(int i =0; i < 26; i++) son[i] =-1; dep =0;}
	};

struct trie {
	vector<node> T;
	vector< vector<int> > V;
	trie() {T.resize(1); V.resize(1);}

	int put(string &s, int id) {
		int akt =0;
		for(uint i =0; i < s.length(); i++) {
			if(T[akt].son[s[i]-'a'] == -1) {
				int n =T.size();
				T.resize(n+1);
				V.resize(n+1);
				T[n].dep =T[akt].dep+1;
				T[akt].son[s[i]-'a'] =n;}
			akt =T[akt].son[s[i]-'a'];}
		V[akt].push_back(id);
		return akt;}

	stack<int> st;
	int lca;
	void DFS(int akt, vector<int> &v, vector<int> &lcp) {
		ALL_THE(V[akt],it) {
			if(!v.empty()) lcp.push_back(T[lca].dep);
			v.push_back(*it);
			lca =akt;}
		for(int i =0; i < 26; i++) if(T[akt].son[i] != -1) {
			st.push(T[akt].son[i]);
			DFS(T[akt].son[i],v,lcp);
			int l =st.top();
			st.pop();
			if(l == lca) lca =st.top();}
		}
	};

int main() {
	int N;
	scanf(" %d",&N);
	trie T;
	char ch[800000+tisic];
	vector<int> node1(N),node2(N);
	for(int i =0; i < N; i++) {
		scanf(" %s",ch);
		string s =(string)ch;
		node1[i] =T.put(s,i);}
	for(int i =0; i < N; i++) {
		scanf(" %s",ch);
		string s =(string)ch;
		node2[i] =T.put(s,i+N);}

	vector<int> V,LCP;
	T.lca =0;
	T.st.push(0);
	T.DFS(0,V,LCP);

	set< pair<int,pair<int,int> > > M;
	vector<int> nxt(2*N,-1), prev(2*N,-1);
	for(int i =1; i < 2*N; i++) nxt[i-1] =i, prev[i] =i-1;
	for(int i =1; i < 2*N; i++) if(V[i]/N != V[i-1]/N) 
		M.insert(make_pair(LCP[i-1],make_pair(i-1,i)));

	vector<int> ans(2*N,-1);
	long long ansS =0;
	for(int i =0; i < N; i++) {
		auto it =M.end(); it--;
		ansS +=it->ff;
		ans[V[it->ss.ff]] =V[it->ss.ss];
		ans[V[it->ss.ss]] =V[it->ss.ff];
		int p =prev[it->ss.ff], n =nxt[it->ss.ss];
		if(p >= 0) M.erase(make_pair(LCP[p],make_pair(p,it->ss.ff)));
		if(n >= 0) M.erase(make_pair(LCP[it->ss.ss],make_pair(it->ss.ss,n)));
		M.erase(it);
		if(p >= 0 && n >= 0) {
			LCP[p] =min(LCP[p],min(LCP[prev[n]],LCP[nxt[p]]));
			prev[n] =p;
			nxt[p] =n;
			if(V[p]/N != V[n]/N) M.insert(make_pair(LCP[p],make_pair(p,n)));}
		else if(p >= 0) nxt[p] =n;
		else if(n >= 0) prev[n] =p;}

	printf("%I64d\n",ansS);
	for(int i =0; i < 2*N; i++) if(ans[i] >= N)
		printf("%d %d\n",i+1,ans[i]-N+1);
	return 0;}

// look at my code
// my code is amazing