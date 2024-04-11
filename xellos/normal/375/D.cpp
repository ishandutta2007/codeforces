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
#define cut 200
// mylittlepony
using namespace std;

struct fin {
    vector<int> T;

    int lastone(int x) {return x&(x^(x-1));}

    void put(int pos, int val) {
        for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;
        }

    int get(int pos) {
        int ret =0;
        for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
        return ret;}
    };

void countI(int R, vector< pair<int,int> > &I, vector<int> &par, vector< vector<int> > &G) {
    ALL_THE(G[R],it) if(*it != par[R]) {
        I[*it].ff =I[R].ss;
        I[*it].ss =I[R].ss+1;
        countI(*it,I,par,G);
        I[R].ss +=I[*it].ss-I[*it].ff;}
    }

int main() {
    cin.sync_with_stdio(0);
    int N,Q,a,b;
    cin >> N >> Q;
    vector<int> C(N);
    for(int i =0; i < N; i++) cin >> C[i];
    vector< vector<int> > G(N);
    for(int i =1; i < N; i++) {
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);}

    vector<int> par(N,-1);
    vector<int> seq;
    par[0] =0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        a =q.front();
        seq.push_back(a);
        ALL_THE(G[a],it) if(par[*it] == -1) {
            par[*it] =a;
            q.push(*it);}
        q.pop();}
    vector<int> seqI(N);
    for(int i =0; i < N; i++) seqI[seq[i]] =i;

    // skonvertuj na intervaly
    vector< pair<int,int> > I(N,make_pair(0,1));
    countI(0,I,par,G);

    // LCA predratanie
    vector< vector<int> > parE(20,vector<int>(N));
    parE[0] =par;
    for(int i =1; i < 20; i++) for(int j =0; j < N; j++)
        parE[i][j] =parE[i-1][parE[i-1][j]];

    // caste farby
    vector<int> pC(100000+tisic,0);
    vector<int> isC(100000+tisic,-1);
    for(int i =0; i < N; i++) pC[C[i]]++;
    int f =0;
    for(int i =0; i <= 100000; i++) if(pC[i] > 0) f++;
    vector<int> C1;
    for(int i =0; i <= 100000; i++) if(pC[i] >= cut) {
        isC[i] =C1.size();
        C1.push_back(i);}
    vector< vector<int > > S1(C1.size(),vector<int>(N+1,0));
    for(int i =0; i < N; i++)
        if(isC[C[i]] >= 0) S1[isC[C[i]]][I[i].ff+1]++;
    for(uint i =0; i < C1.size(); i++)
        for(int j =0; j < N; j++) S1[i][j+1] +=S1[i][j];

    // vzacne farby
    vector< vector<int> > S2(cut, vector<int>(N,0));
    fin F; F.T.resize(N+1,0);
    vector< vector<int> > sp(100000+tisic);
    for(int i =N-1; i >= 0; i--) if(pC[C[seq[i]]] < cut) sp[C[seq[i]]].push_back(i);
    // i vyskytov
    set<int> S;
    for(int i =0; i <= 100000; i++) {
        for(uint j =0; j < sp[i].size(); j++) {
            F.put(I[seq[sp[i][j]]].ff,1);
            S.insert(sp[i][j]);}

        while(!S.empty()) {
            a =seq[*S.rbegin()];
            S.erase(--S.end());
            b =F.get(I[a].ss-1)-F.get(I[a].ff-1);
            S2[b][a]++;
            // binsearch vrchol po ktory to ide
            if(F.get(N-1) == b) continue;
            int x =a, k =19;
            while(k >= 0 && x > 0) {
                int y =parE[k][x];
                if(F.get(I[y].ss-1)-F.get(I[y].ff-1) != b) k--;
                else x =y;}
            S.insert(seqI[par[x]]);
            S2[b][par[x]]--;}

        for(uint j =0; j < sp[i].size(); j++) F.put(I[seq[sp[i][j]]].ff,-1);}

    // do otcov
    for(int i =1; i < cut; i++) for(int j =N-1; j > 0; j--)
        S2[i][par[seq[j]]] +=S2[i][seq[j]];
    // nuly
    for(int i =0; i < N; i++) {
        a =0;
        for(int j =0; j < cut; j++) a +=S2[j][i];
        S2[0][i] =f-C1.size()-a;}
    // dopln na < i
    for(int i =0; i < N; i++) for(int j =0; j < cut-1; j++)
        S2[j+1][i] +=S2[j][i];

    // odpovede
    for(int q =0; q < Q; q++) {
        cin >> a >> b;
        a--;
        int ans =0;
        // prirataj caste
        for(uint i =0; i < C1.size(); i++) ans +=(int)(S1[i][I[a].ss]-S1[i][I[a].ff] >= b);
        // prirataj vzacne
        if(b <= cut) ans +=f-C1.size()-S2[b-1][a];
        cout << ans << "\n";}
    return 0;}

// look at my code
// my code is amazing