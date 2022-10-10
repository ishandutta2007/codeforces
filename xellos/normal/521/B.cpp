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

vector< pair<int,int> > C;
map< pair<int,int>, int> Cm;

int safe(int i) {
	int ret =0;
	for(int j =-1; j <= 1; j++) 
		if(Cm.find(make_pair(C[i].ff+j,C[i].ss-1)) != Cm.end()) ret++;
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	C.resize(N);
	for(int i =0; i < N; i++) {
		cin >> C[i].ff >> C[i].ss;
		Cm[C[i]] =i;}
	vector<long long> costs(N+1,1);
	long long mod =1000000009;
	for(int i =1; i <= N; i++) {
		costs[i] =(costs[i-1]*N)%mod;
		if(costs[i] < 0) costs[i] +=mod;}

	vector< vector<int> > G(N);
	vector<int> D(N,0);
	set<int> F;
	long long ans =0;
	int a =0, b =N-1;

	for(int i =0; i < N; i++) {
		bool ok =false;
			while(!F.empty()) {
				int x =(i%2 == 0)?(*F.rbegin()):(*F.begin());
				if(i%2 == 0 && x < a) break;
				if(i%2 != 0 && x > b) break;
				bool f =true;
				for(int j =-1; j <= 1; j++) {
					auto jt =Cm.find(make_pair(C[x].ff+j,C[x].ss+1));
					if(jt != Cm.end() && safe(jt->ss) == 1) {
						G[jt->ss].push_back(x);
						D[x]++;
						f =false;}
					}
				if(i%2 == 0) F.erase(--F.end());
				else F.erase(F.begin());
				if(!f) continue;
				ans =(ans+costs[N-i-1]*x)%mod;
				Cm.erase(C[x]);
//				cout << x << "\n";
				ALL_THE(G[x],it) {
					D[*it]--;
					if(D[*it] == 0) F.insert(*it);}
				G[x].clear();
				ok =true;
				break;}
		if(ok) continue;
			while(b >= a) {
				// je volna?
				int x =(i%2 == 0)?b:a;
				bool f =true;
				for(int j =-1; j <= 1; j++) {
					auto jt =Cm.find(make_pair(C[x].ff+j,C[x].ss+1));
					if(jt != Cm.end() && safe(jt->ss) == 1) {
						G[jt->ss].push_back(x);
						D[x]++;
						f =false;}
					}
				if(!f) {
					F.insert(x);
					if(i%2 == 0) b--;
					else a++;
					continue;}
				ans =(ans+costs[N-i-1]*x)%mod;
				Cm.erase(C[x]);
//				cout << x << ".\n";
				ALL_THE(G[x],it) {
					D[*it]--;
					if(D[*it] == 0) F.insert(*it);}
				G[x].clear();
				if(i%2 == 0) b--;
				else a++;
				ok =true;
				break;}
		if(ok) continue;
			while(!F.empty()) {
				int x =(i%2 == 0)?(*F.rbegin()):(*F.begin());
				bool f =true;
				for(int j =-1; j <= 1; j++) {
					auto jt =Cm.find(make_pair(C[x].ff+j,C[x].ss+1));
					if(jt != Cm.end() && safe(jt->ss) == 1) {
						G[jt->ss].push_back(x);
						D[x]++;
						f =false;}
					}
				if(i%2 == 0) F.erase(--F.end());
				else F.erase(F.begin());
				if(!f) continue;
				ans =(ans+costs[N-i-1]*x)%mod;
				Cm.erase(C[x]);
//				cout << x << "\n";
				ALL_THE(G[x],it) {
					D[*it]--;
					if(D[*it] == 0) F.insert(*it);}
				G[x].clear();
				ok =true;
				break;}
			}
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing