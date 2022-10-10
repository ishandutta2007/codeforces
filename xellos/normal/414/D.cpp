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
#define soclose 1e-9
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittledoge
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,K,a,b;
    long long P, S =0;
    cin >> N >> K >> P;
    vector< vector<int> > G(N);
    for(int i =0; i < N-1; i++) {
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);}
    
    vector<int> dep(N,-1);
    vector<int> depP(N+1,0);
    queue<int> q;
    q.push(0); dep[0] =0; depP[0] =1;
    while(!q.empty()) {
        a =q.front();
        ALL_THE(G[a],it) if(dep[*it] == -1) {
            dep[*it] =dep[a]+1;
            depP[dep[*it]]++;
            q.push(*it);}
        q.pop();}
    
    a =b =1;
    int k =0, poc =0, ans =0;
    while(b < N) {
        S +=1LL*(depP[a]-k)*(b-a);
        poc +=depP[a]-k;
        k =depP[a];
        while(a < b && S > P) {
            S -=1LL*k*(b-a);
            poc -=k;
            a++;
            k =depP[a];}
        if((P-S)/(b-a+1) > 0 && a > 1) {
            k =min(1LL*depP[a-1],1LL*(P-S)/(b-a+1));
            poc +=k;
            S +=k*(b-a+1);
            a--;}
        ans =max(ans,poc);
        b++;
        S +=poc;
        if(b < N) poc +=depP[b];}
    
    cout << min(ans,K) << "\n";
    return 0;}
        
// look at my code
// my code is amazing