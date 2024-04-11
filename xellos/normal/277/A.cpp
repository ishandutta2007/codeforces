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
    int N,M,K,a;
    cin >> N >> M;
    
    vector< vector<int> > jaz(M);
    int x =0;
    vector< vector<int> > adjL(N);
    for(int i =0; i < N; i++) {
        cin >> K;
        if(K == 0) x++;
        for(int j =0; j < K; j++) {
            cin >> a;
            jaz[--a].push_back(i);}}
    for(int i =0; i < M; i++) for(int j =0; j < jaz[i].size(); j++) for(int k =j+1; k < jaz[i].size(); k++) {
        adjL[jaz[i][j]].push_back(jaz[i][k]);
        adjL[jaz[i][k]].push_back(jaz[i][j]);}
    
    queue<int> q;
    vector<int> com(N,-1);
    a =0;
    for(int i =0; i < N; i++) if(com[i] == -1) {
        q.push(i);
        com[i] =a;
        while(!q.empty()) {
            ALL_THE(adjL[q.front()],it) if(com[*it] == -1) {
                com[*it] =a;
                q.push(*it);}
            q.pop();}
        a++;}
    if(x == N) a++;
    cout << a-1 << endl;
    return 0;}
        
// look at my code
// my code is amazing