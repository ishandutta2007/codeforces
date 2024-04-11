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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int N,K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i =0; i < N; i++) cin >> P[i];

    // prvy zivy: i, kedy najskor?
    queue<int> q;
    vector<int> T(N+1,K+1);
    vector<bool> done(N+1,false);
    T[0] =0; q.push(0);
    while(!q.empty()) {
        // za nim dakto trafi
        int a =q.front();
        if(done[a]) {q.pop(); continue;}
        done[a] =true;
        int x =a;
        bool b =false;
        for(int i =a+1; i < N; i++) {
            if(P[i] > 0) x =i;
            if(P[i] == 100) b =true;}
        // on netrafi, jeho trafia
        if(P[a] < 100 && x > a && T[a+1] > T[a]+1) {
            T[a+1] =T[a]+1;
            q.push(a+1);}
        // on trafi niekolkych, jeho trafia
        for(int i =a+2; i <= x+1; i++) // prvy zivy
            if(P[a] > 0 && (!b || a+2 == i) && T[i] > T[a]+i-a-1) {
                T[i] =T[a]+i-a-1;
                q.push(i);}
        q.pop();}

    int ans =0;
    for(int i =0; i <= N; i++) {
        if(T[i] <= K) ans++; // nic dalsie
        if(i == N) continue;
        // za nim j zomrie
        bool ok =true;
        for(int j =i+1; j < N; j++) if(P[j] == 100) ok =false;
        if(!ok || P[i] == 0) continue;
        for(int j =1; j < N-i; j++) if(T[i]+j <= K) ans++;}
    cout << ans << "\n";
    return 0;}

// look at my code
// my code is amazing