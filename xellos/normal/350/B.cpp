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
    int N,a;
    cin >> N;
    vector< vector<int> > son(N);
    vector<int> D(N,N+1);
    vector<int> ako(N,-1);
    queue<int> q;
    for(int i =0; i < N; i++) {
        cin >> a;
        if(a == 1) {
            D[i] =0;
            q.push(i);}}
    vector<int> ok(N,0);
    
    for(int i =0; i < N; i++) {
        cin >> a;
        if(a > 0) {
            ok[--a]++;
            son[i].push_back(a);}}

    while(!q.empty()) {
        a =q.front();
        ALL_THE(son[a],it) if(D[*it] > D[a]+1 && ok[*it] == 1) {
            D[*it] =D[a]+1;
            ako[*it] =a;
            q.push(*it);}
        q.pop();}
    
    a =0;
    for(int i =0; i < N; i++) if(D[i] <= N) a =max(a,D[i]);
    cout << a+1 << "\n";
    for(int i =0; i < N; i++) if(D[i] == a) {
        a =i;
        cout << a+1;
        while(ako[a] != -1) {
            a =ako[a];
            cout << " " << a+1;}
        cout << "\n";
        return 0;}
    return 0;}
        
// look at my code
// my code is amazing