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
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,P;
	cin >> N >> P;
	vector<int> poc(N,0);
	vector< pair<int,int> > V(N);
	for(int i =0; i < N; i++) {
		cin >> V[i].ff >> V[i].ss;
		poc[--V[i].ff]++;
		poc[--V[i].ss]++;
		if(V[i].ss < V[i].ff) swap(V[i].ss,V[i].ff);}
	long long ans =0;
	int a =N-1;
	vector<int> pocS =poc;
	sort(pocS.begin(),pocS.end());
	for(int i =0; i < N; i++) {
		while(a > i && pocS[a]+pocS[i] >= P) a--;
		a =max(a,i);
		ans +=(N-1-a);}
	sort(V.begin(),V.end());
	for(int i =0; i < N; i++) if(i == 0 || V[i-1] != V[i])
		if(poc[V[i].ff]+poc[V[i].ss] >= P) {
			a =i;
			while(a < N && V[a] == V[i]) a++;
			if(poc[V[i].ff]+poc[V[i].ss]-a+i < P) ans--;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing