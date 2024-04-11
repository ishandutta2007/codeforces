// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define ull unsigned long long
#define sent(x,y) (x >= 0 && y >= 0 && x < N && y < N)
// mylittlepony
using namespace std;
using namespace std::tr1;
 
vector< vector<int> > Next;
vector< vector<int> > Prev;
vector< vector< pair<int,int> > > sol;
int N;
string s;

void countS(int a, int b) {
	if(sol[a][b].ff != -1) return;
	if(a > b) {sol[a][b] =make_pair(0,-1); return;}
	sol[a][b].ff =1; sol[a][b].ss =s[a]-'a';
	for(int i =0; i < 26; i++) if(sent(Next[i][a]+1,Prev[i][b]-1)) {
		if(Next[i][a] >= Prev[i][b]) continue;
		countS(Next[i][a]+1,Prev[i][b]-1);
		if(sol[Next[i][a]+1][Prev[i][b]-1].ff+2 > sol[a][b].ff) {
			sol[a][b].ff =sol[Next[i][a]+1][Prev[i][b]-1].ff+2;
			sol[a][b].ss =i;}
		if(sol[a][b].ff == 100) return;}
	}

int main() {
	cin >> s;
	N =s.length();
	if(N >= 2600) {
		vector<int> poc(26,0);
		for(int i =0; i < N; i++) poc[s[i]-'a']++;
		for(int i =0; i < 26; i++) if(poc[i] >= 100) {
			for(int j =0; j < 100; j++) cout << (char)(i+'a');
			cout << "\n";
			return 0;}}
	Next.resize(26, vector<int>(N,N+1));
	Prev.resize(26, vector<int>(N,-1));
	for(int i =0; i < 26; i++) {
		for(int j =0; j < N; j++) {
			if(s[j]-'a' == i) Prev[i][j] =j;
			else if(j > 0) Prev[i][j] =Prev[i][j-1];}
		for(int j =N-1; j >= 0; j--) {
			if(s[j]-'a' == i) Next[i][j] =j;
			else if(j < N-1) Next[i][j] =Next[i][j+1];}}
	
	sol.resize(N, vector< pair<int,int> >(N, make_pair(-1,-1)));
	countS(0,N-1);
	string ans;
	string ans2;
	int a =0, b =N-1;
	while(sol[a][b].ff > 0) {
		ans +='a'+sol[a][b].ss;
		int x =a, y =b, z =sol[a][b].ss;
		if(Next[z][x] != Prev[z][y]) ans2 +='a'+z;
		a =Next[z][x]+1;
		b =Prev[z][y]-1;
		if(ans.size()+ans2.size() == 100 || a > b) break;}
	cout << ans;
	for(int i =ans2.length()-1; i >= 0; i--) cout << ans2[i];
	cout << "\n";
	return 0;}
        
// look at my code
// my code is amazing