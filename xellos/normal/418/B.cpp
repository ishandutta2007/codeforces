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
#define OVER9000 2234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

struct fr {
	long long X,mon;
	int pr;

	bool operator<(const fr &F) const {
		return mon < F.mon;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	long long B;
	cin >> N >> M >> B;
	vector<fr> F(N);
	for(int i =0; i < N; i++) {
		int m,a;
		cin >> F[i].X >> F[i].mon >> m;
		F[i].pr =0;
		for(int j =0; j < m; j++) {
			cin >> a;
			F[i].pr |=1<<(a-1);}
		}
	sort(F.begin(),F.end());

	vector<long long> A(1<<M,OVER9000);
	A[0] =0;
	long long ans =OVER9000;
	for(int i =0; i < N; i++) {
		vector<long long> A2 =A;
		for(int j =(1<<M)-1; j >= 0; j--) A2[j|F[i].pr] =min(A2[j|F[i].pr],A[j]+F[i].X);
		A =A2;
		ans =min(ans,A[(1<<M)-1]+B*F[i].mon);}

	if(ans == OVER9000) cout << "-1\n";
	else cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing