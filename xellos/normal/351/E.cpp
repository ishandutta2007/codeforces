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
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    vector<bool> live(N,true);
    int ans =0;

    while(true) {
        // choose bounding
        int a =0, m =-1;
        vector<int> A;
        for(int i =0; i < N; i++) if(live[i]) m =max(m,abs(V[i]));
        if(m == -1) break;
        for(int i =0; i < N; i++) if(live[i]) {
            if(abs(V[i]) == m) {A.push_back(a); live[i] =false;}
            a++;}
//      ALL_THE(A,it) cout << *it << " ";
        
        // choose the cheapest option
        int K =A.size();
        int aktR =OVER9000;
        for(int x =0; x <= K; x++) {
            int akt =0;
            for(int i =0; i < x; i++) akt +=A[i];
            if(x > 0) akt -=x*(x-1)/2;
            for(int i =x; i < K; i++) akt +=(a-1-A[i]);
            if(x < K) akt -=(K-x)*(K-x-1)/2;
            aktR =min(aktR,akt);}
//      cout << aktR << "\n";
        ans +=aktR;}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing