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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
	
struct DiffSets {
	multiset<int> M,L;

	void Add(int x) {
		if(L.find(x) != L.end()) L.erase(L.find(x));
		else M.insert(x);}
	
	void Rem(int x) {
		if(M.find(x) != M.end()) M.erase(M.find(x));
		else L.insert(x);}
	
	bool Equiv() {return (L.empty() && M.empty());}
	};
	
int main() {
    cin.sync_with_stdio(0);
    int N,M,P;
    cin >> N >> M >> P;
    vector<int> A(N), B(M);
    for(int i =0; i < N; i++) cin >> A[i];
    for(int i =0; i < M; i++) cin >> B[i];
    
    set<int> ans;
    for(int i =0; i < P; i++) if(i+(long long)(M-1)*(long long)P < (long long)N) {
    	DiffSets S;
		for(int j =0; j < M; j++) {
    		S.Rem(B[j]);
    		S.Add(A[i+j*P]);}
    	
    	for(int j =i; ; j +=P) {
			if(S.Equiv()) ans.insert(j+1);
			if(j+M*P >= N) break;
			S.Add(A[j+M*P]);
			S.Rem(A[j]);}
		}
	
	cout << ans.size() << "\n";
	ALL_THE(ans,it) {
		if(it != ans.begin()) cout << " ";
		cout << *it;}
	cout << "\n";
    return 0;}
        
// look at my code
// my code is amazing