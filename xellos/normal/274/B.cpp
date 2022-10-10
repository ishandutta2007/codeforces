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
#define tritisic 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// mylittlepony
using namespace std;
	
int main() {
    int N,a,b;
    cin >> N;
    vector<long long> V(N);
    vector< vector<int> > adjL(N);
    for(int i =1; i < N; i++) {
        cin >> a >> b;
        adjL[--a].push_back(--b);
        adjL[b].push_back(a);}
    queue<int> q;
    stack<int> s;
    vector<int> D(N,tritisic);
    D[0] =0;
    q.push(0);
    while(!q.empty()) {
        s.push(q.front());
        for(int i =0; i < adjL[q.front()].size(); i++) if(D[adjL[q.front()][i]] > D[q.front()]+1) {
            D[adjL[q.front()][i]] =D[q.front()]+1;
            q.push(adjL[q.front()][i]);}
        q.pop();}
    for(int i =0; i < N; i++) cin >> V[i];
    
    vector< pair<long long,long long> > minO(N,make_pair(0,0));
    while(!s.empty()) {
        for(int i =0; i < adjL[s.top()].size(); i++) if(D[adjL[s.top()][i]] > D[s.top()]) {
            minO[s.top()].first =max(minO[s.top()].first,minO[adjL[s.top()][i]].first);
            minO[s.top()].second =max(minO[s.top()].second,minO[adjL[s.top()][i]].second);}
        V[s.top()] +=minO[s.top()].first-minO[s.top()].second;
        if(V[s.top()] > 0) minO[s.top()].second +=V[s.top()];
        else minO[s.top()].first -=V[s.top()];
        s.pop();}
    cout << minO[0].first+minO[0].second << endl;
    return 0;}
        
// look at my code
// my code is amazing