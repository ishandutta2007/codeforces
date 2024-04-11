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
    int N,M,P,Q,a,b,c;
    cin >> N >> M >> P >> Q;
    vector< vector< pair<int,int> > > G(N);
    pair<int,int> E;
    int co =0;
    for(int i =0; i < M; i++) {
        cin >> a >> b >> c;
        if(M == 100000 && c < 1000000) co++;
        G[--a].push_back(make_pair(--b,c));
        E =make_pair(a,b);
        G[b].push_back(make_pair(a,c));}

    vector<int> C(N,-1);
    vector<int> fC;
    vector<int> S;
    for(int i =0; i < N; i++) if(C[i] == -1) {
        queue<int> q;
        q.push(i);
        C[i] =fC.size();
        long long Sa =0;
        while(!q.empty()) {
            a =q.front();
            ALL_THE(G[a],it) Sa +=it->ss;
            ALL_THE(G[a],it) if(C[it->ff] == -1) {
                C[it->ff] =fC.size();
                q.push(it->ff);}
            q.pop();}
        fC.push_back(i);
        S.push_back(min(1000000000LL,Sa/2));}

    if(fC.size()-Q < 0 || fC.size()-Q > P || (M == 0 && fC.size() == Q && P > 0)) {
        cout << "NO\n";
        return 0;}
    
    cout << "YES\n";
    set< pair<int,int> > X;
    for(int i =0; i < fC.size(); i++) X.insert(make_pair(S[i],i));
    for(int i =0; i < fC.size()-Q; i++) {
        pair<int,int> p1 =*X.begin(); X.erase(X.begin());
        pair<int,int> p2 =*X.begin(); X.erase(X.begin());
        E =make_pair(fC[p1.ss],fC[p2.ss]);
        cout << fC[p1.ss]+1 << " " << fC[p2.ss]+1 << "\n";
        p1.ff =min(1000000000,p2.ff+p1.ff);
        p1.ff =min(1000000000,2*p1.ff+1);
        X.insert(p1);}
    
    
    for(int i =0; i < P+Q-fC.size(); i++) cout << E.ff+1 << " " << E.ss+1 << "\n";
    return 0;}
        
// look at my code
// my code is amazing