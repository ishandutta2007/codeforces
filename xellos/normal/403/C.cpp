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
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int N,a;
    cin >> N;
    vector< vector<int> > G(N), Gi(N);
    vector<int> D(N,0), E(N,0);
    for(int i =0; i < N; i++) for(int j =0; j < N; j++) {
        cin >> a;
        if(a > 0 && i != j) {
            G[i].push_back(j);
            Gi[j].push_back(i);
            D[i]++, E[j]++;}}

    queue<int> q;
    vector<int> V(N,false); V[0] =true;
    q.push(0);
    while(!q.empty()) {
        a =q.front();
        ALL_THE(G[a],it) if(!V[*it]) {
            V[*it] =true;
            q.push(*it);}
        q.pop();}
    q.push(0);
    vector<int> W(N,false); W[0] =true;
    while(!q.empty()) {
        a =q.front();
        ALL_THE(Gi[a],it) if(!W[*it]) {
            W[*it] =true;
            q.push(*it);}
        q.pop();}
    for(int i =0; i < N; i++) if(!V[i] || !W[i]) {cout << "NO\n"; return 0;}
    cout << "YES\n";
    return 0;}

// look at my code
// my code is amazing