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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// mylittlepony
using namespace std;
    
int main() {
    int N,M,Q,a;
    cin >> N >> M >> Q;
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
    vector< vector<int> > S(M); // all elements of set
    vector< vector<bool> > E(M); // is element in set?
    vector<int> large;
    for(int i =0; i < M; i++) {
        cin >> a;
        S[i].resize(a);
        if(a > 300) {
            E[i].resize(N,false);
            large.push_back(i);}
        for(int j =0; j < S[i].size(); j++) {
            cin >> S[i][j]; S[i][j]--;
            if(S[i].size() > 300) E[i][S[i][j]] =true;}
        }

    // the sums right now
    vector<long long> sum(M,0);
    for(int i =0; i < M; i++) ALL_THE(S[i],it) sum[i] +=A[*it];
    
    // large-set intersections
    vector< vector<long long> > I(M);
    ALL_THE(large,it) {
        I[*it].resize(M,0);
        for(int i =0; i < M; i++) ALL_THE(S[i],jt)
            if(E[*it][*jt]) I[*it][i]++;
        }

    vector<long long> dA(N,0); // updates on A[i]
    vector<long long> dI(M,0); // updates on S[i]
    
    string t;
    for(int q =0; q < Q; q++) {
        cin >> t >> a;
        if(t == "?") {
            long long res =sum[a-1];
            if(S[a-1].size() <= 300) {
                ALL_THE(large,it) res +=dI[*it]*I[*it][a-1];
                ALL_THE(S[a-1],it) res +=dA[*it];}
            cout << res << "\n";
            continue;}
            
        long long x; cin >> x;
        if(S[a-1].size() <= 300)
            ALL_THE(S[a-1],it) dA[*it] +=x;
        else dI[a-1] +=x;
        // update all intersections with large intervals
        ALL_THE(large,it) sum[*it] +=I[*it][a-1]*x;
        }
    return 0;}
        
// look at my code
// my code is amazing