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

struct fin {
    vector<int> T;

    fin(int N) {T.resize(N+1,0);}

    int lastone(int x) {return x&(x^(x-1));}

    void put(int pos, int val) {
        for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

    int get(int pos) {
        int ret =0;
        for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
        return ret;}
    };

int main() {
    cin.sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector< pair<int,int> > S(N);
    for(int i =0; i < N; i++) cin >> S[i].ff >> S[i].ss;
    sort(S.begin(),S.end());

    vector< vector<int> > qu(M);
    vector<int> I(M,0);
    map< int, vector<int> > A;
    for(int i =0; i < M; i++) {
        int a,b; cin >> a;
        for(int j =0; j < a; j++) {
            cin >> b;
            qu[i].push_back(b);
            if(A.find(b) == A.end()) A[b] =vector<int>(1,i);
            else A[b].push_back(i);}}
    for(int i =0; i < M; i++) qu[i].push_back(1000001);

    multiset<int> E;
    fin F(1000000+tisic);
    vector<int> ans(M,0);
    int a =0;
    ALL_THE(A,it) {
        // pridaj dobre zaciatky
        while(a < N && S[a].ff <= it->ff) {
            E.insert(S[a].ss);
            F.put(S[a].ss,1);
            a++;}
        // zahod konce
        while(!E.empty() && *E.begin() < it->ff) {
            F.put(*E.begin(),-1);
            E.erase(E.begin());}

        vector<int> V =it->ss;
        for(int i =0; i < V.size(); i++) {
            ans[V[i]] +=F.get(qu[V[i]][I[V[i]]+1]-1);
            I[V[i]]++;}}

    for(int i =0; i < M; i++) cout << ans[i] << "\n";
    return 0;}

// look at my code
// my code is amazing