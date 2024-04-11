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

struct Sp {
	int a,b,id;

	bool operator<(const Sp &S) const {
		if(a != S.a) return a < S.a;
		return b < S.b;}
	};

struct S2 {
	int c,d,k,id;

	bool operator<(const S2 &S) const {
		if(c != S.c) return c < S.c;
		return d < S.d;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<Sp> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i].a >> A[i].b;
		A[i].id =i;}
	int M;
	cin >> M;
	vector<S2> B(M);
	for(int i =0; i < M; i++) {
		cin >> B[i].c >> B[i].d >> B[i].k;
		B[i].id =i;}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	vector<int> ans(N,-1);
	multimap<int,int> m;
	int a =0;
	for(int i =0; i < N; i++) {
		while(a < M && B[a].c <= A[i].a) {
			m.insert(make_pair(B[a].d,a));
			a++;}
		auto it =m.lower_bound(A[i].b);
		if(it == m.end()) {cout << "NO\n"; return 0;}
		ans[A[i].id] =B[it->ss].id;
		B[it->ss].k--;
		if(B[it->ss].k == 0) m.erase(it);}

	cout << "YES\n";
	for(int i =0; i < N; i++) cout << ans[i]+1 << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing