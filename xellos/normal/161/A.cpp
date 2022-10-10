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

struct interv {
	int z,k,id;

	bool operator<(const interv &A) const {
		return z < A.z;}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,x,y;
	cin >> N >> M >> x >> y;
	vector<interv> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i].z;
		A[i].k =A[i].z+y;
		A[i].z -=x;
		A[i].id =i+1;}
	sort(begin(A),end(A));
	vector< pair<int,int> > B(M);
	for(int i =0; i < M; i++) {
		cin >> B[i].ff;
		B[i].ss =i+1;}
	sort(begin(B),end(B));

	vector< pair<int,int> > ans;
	int a =0;
	set< pair<int,int> > S;
	for(int i =0; i < M; i++) {
		while(a < N && A[a].z <= B[i].ff) {
			S.insert(make_pair(A[a].k,A[a].id));
			a++;}
		while(!S.empty() && S.begin()->ff < B[i].ff) S.erase(S.begin());
		if(S.empty()) continue;
		ans.push_back(make_pair(S.begin()->ss,B[i].ss));
		S.erase(S.begin());}

	cout << ans.size() << "\n";
	ALL_THE(ans,it) cout << it->ff << " " << it->ss << "\n";
	return 0;}

// look at my code
// my code is amazing