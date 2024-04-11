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
    int N,a,b,t;
    cin >> N;
    vector< vector< pair<int,int> > > G(N);
    for(int i =1; i < N; i++) {
        cin >> a >> b >> t;
        G[--a].push_back(make_pair(--b,t));
        G[b].push_back(make_pair(a,t));}

    queue<int> q;
    vector<int> par(N,-1);
    vector<bool> good(N,false);
    q.push(0);
    while(!q.empty()) {
        a =q.front();
        ALL_THE(G[a],it) if(par[it->ff] == -1) {
            par[it->ff] =a;
            if(it->ss == 2) good[it->ff] =true;
            q.push(it->ff);}
        q.pop();}

    vector<int> D(N);
    for(int i =0; i < N; i++) D[i] =G[i].size();
    for(int i =1; i < N; i++) if(D[i] == 1) {
        D[i] =0;
        q.push(i);}

    vector<int> ans;
    while(!q.empty()) {
        a =q.front();
        if(good[a]) {
            ans.push_back(a);
            q.pop();
            continue;}
        D[par[a]]--;
        if(D[par[a]] == 1) q.push(par[a]);
        q.pop();}

    cout << ans.size() << "\n";
    for(int i =0; i < ans.size(); i++) cout << ans[i]+1 << ((i == ans.size()-1)?"\n":" ");
    return 0;}

// look at my code
// my code is amazing