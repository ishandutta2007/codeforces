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
    
int main() {
    cin.sync_with_stdio(0);
    int N,M,l,r,x;
    cin >> N >> M;
    set<int> live;
    for(int i =0; i < N; i++) live.insert(i);
    vector<int> ans(N,-1);
    for(int i =0; i < M; i++) {
        cin >> l >> r >> x;
        l--, r--, x--;
        auto jt =live.upper_bound(r), it =live.lower_bound(l);
        while(it != jt) {
            if(*it == x) {it++; continue;}
            ans[*it] =x;
            auto kt =it; it++;
            live.erase(kt);}
        }
    for(int i =0; i < N; i++) cout << ans[i]+1 << ((i == N-1)?"\n":" ");
    return 0;}
        
// look at my code
// my code is amazing