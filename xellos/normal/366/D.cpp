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
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
struct infoE {
    int a,b,l,r;
    
    bool operator<(const infoE &A) const {
        return l < A.l;}
    };
    
int main() {
    cin.sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector<infoE> E(M);
    for(int i =0; i < M; i++) {
        cin >> E[i].a >> E[i].b >> E[i].l >> E[i].r;
        E[i].a--, E[i].b--;}
    sort(E.begin(),E.end());
    
    vector< vector<infoE> > G(N);
    int ans =-1;
    for(int i =0; i < M; i++) {
        G[E[i].a].push_back(E[i]);
        swap(E[i].a,E[i].b);
        G[E[i].a].push_back(E[i]);
        
        // kolko je max. horna hranica?
        priority_queue< pair<int,int> > q;
        vector<int> A(N,-1);
        A[0] =OVER9000;
        ALL_THE(G[0],it) q.push(make_pair(it->r,it->b));
        while(!q.empty()) {
            pair<int,int> p =q.top();
            q.pop();
            if(A[p.ss] >= 0) continue;
            A[p.ss] =p.ff;
            ALL_THE(G[p.ss],it) if(A[it->b] == -1) 
                q.push(make_pair(min(it->r,A[p.ss]),it->b));
            }
        if(A[N-1] >= E[i].l) ans =max(ans,A[N-1]-E[i].l+1);
        }
    if(ans <= 0) cout << "Nice work, Dima!\n";
    else cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing