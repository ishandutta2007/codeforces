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
#define ff first
#define ss second
// mylittlepony
using namespace std;
    
int N,a,b;
vector< vector<int> > G;
vector<long long> A;
vector<int> dep;
vector<long long> minR;

long long gcd(long long a, long long b) {
    if(a > b) swap(a,b);
    if(a == 0) return b;
    return gcd(b%a,a);}

long long lcm(long long a, long long b) {
    if(a > b) swap(a,b);
    if(a == 0) return 0;
    return b*(a/gcd(a,b));}

void solve(int R) {
    if(G[R].size() == 1 && R != 0) return;
    ALL_THE(G[R],it) if(dep[*it] > dep[R]) {
        solve(*it);
        A[R] =max(A[*it],A[R]);}
    ALL_THE(G[R],it) if(dep[*it] > dep[R]) {
        if(minR[R] > A[R] || minR[R] < 0) minR[R] =0;
        minR[R] =lcm(minR[R],minR[*it]);}
    if(minR[R] == 0) {A[R] =0; return;}
    A[R] =0;
    long long k =1000000000000000000LL;
    ALL_THE(G[R],it) if(dep[*it] > dep[R]) 
        k =min(A[*it]/minR[R],k);
    A[R] =(G[R].size()-(int)(R > 0))*k*minR[R];
    if(minR[R] <= A[R]) minR[R] =(G[R].size()-(int)(R > 0))*minR[R];
    return;}

int main() {
    cin >> N;
    G.resize(N);
    A.resize(N);
    for(int i =0; i < N; i++) cin >> A[i];
    for(int i =1; i < N; i++) {
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);}
    
    queue<int> q;
    q.push(0);
    dep.resize(N,-1);
    dep[0] =0;
    stack<int> S;
    while(!q.empty()) {
        a =q.front();
        S.push(a);
        ALL_THE(G[a],it) if(dep[*it] == -1) {
            dep[*it] =dep[a]+1;
            q.push(*it);}
        q.pop();}
    
    vector< map<int,int> > P(N);
    while(!S.empty()) {
        if(G[S.top()].size() == 1 && S.top() != 0) {S.pop(); continue;}
        int d =G[S.top()].size()-(int)(S.top() > 0);
        for(int i =2; i*i <= d; i++) if(d%i == 0) {
            int x =0;
            while(d%i == 0) {d /=i; x++;}
            P[S.top()][i] =x;}
        if(d > 1) P[S.top()][d] =max(P[S.top()][d],1);
        ALL_THE(G[S.top()],it) if(dep[*it] > dep[S.top()]) ALL_THE(P[*it],jt) 
            P[S.top()][jt->ff] =max(P[S.top()][jt->ff],jt->ss);
        S.pop();}
    long long B =1;
    ALL_THE(P[0],it) for(int i =0; i < it->ss; i++) {
        if(B > 100000000000000LL) B =0;
        B *=it->ff;}

    minR.resize(N,1);
    long long L =0;
    ALL_THE(A,it) L +=*it;
    if(B == 0) {cout << L << "\n"; return 0;}
    solve(0);
    cout << L-A[0] << "\n";
    return 0;}
        
// look at my code
// my code is amazing