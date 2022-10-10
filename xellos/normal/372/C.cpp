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
#define OVER9000 123456789012345678LL
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int N,M,D;
    cin >> N >> M >> D;
    D =min(D,N);
    vector<long long> A(M), B(M);
    vector<int> T(M+1,0);
    for(int i =0; i < M; i++) {
        cin >> A[i] >> B[i] >> T[i+1];
        A[i]--;}

    vector<long long> ans(N,0);
    vector<long long> ansN(N,0);
    deque< pair<long long,int> > q;
    for(int k =0; k < M; k++) {
        int b =D*min(N/D+tisic,T[k+1]-T[k]);

        for(int i =0; i < N; i++) {
            long long a =ans[i];
            while(!q.empty() && q.front().ff >= a) q.pop_front();
            q.push_front(make_pair(a,i));
            while(q.back().ss < i-b) q.pop_back();
            ansN[i] =abs(i-A[k])+q.back().ff;}
        while(!q.empty()) q.pop_back();

        for(int i =N-1; i >= 0; i--) {
            long long a =ans[i];
            while(!q.empty() && q.front().ff >= a) q.pop_front();
            q.push_front(make_pair(a,i));
            while(q.back().ss > b+i) q.pop_back();
            ans[i] =min(ansN[i],abs(i-A[k])+q.back().ff);}
        while(!q.empty()) q.pop_back();
        }

    long long ansR =OVER9000;
    for(int i =0; i < N; i++) ansR =min(ansR,ans[i]);
    ansR *=-1;
    for(int i =0; i < M; i++) ansR +=B[i];
    cout << ansR << "\n";
    return 0;}

// look at my code
// my code is amazing