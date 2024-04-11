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
    
struct infoO {
    int t,l,r,x;};
    
int main() {
    cin.sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector<infoO> Op(M);
    vector<int> D(N,0);
    vector<int> A(N,1000000000);

    for(int i =0; i < M; i++) {
        cin >> Op[i].t >> Op[i].l >> Op[i].r >> Op[i].x;
        Op[i].l--;
        for(int j =Op[i].l; j < Op[i].r; j++) {
            if(Op[i].t == 1) D[j] +=Op[i].x;
            else A[j] =min(A[j],Op[i].x-D[j]);}
        }
    
    vector<int> B =A;
    bool ok =true;
    for(int i =0; i < M; i++) {
        int m =-1000000000;
        for(int j =Op[i].l; j < Op[i].r; j++) {
            if(Op[i].t == 1) B[j] +=Op[i].x;
            else m =max(m,B[j]);}
        if(Op[i].t == 2 && m != Op[i].x) {cout << "NO\n"; return 0;}
        }
    
    cout << "YES\n";
    for(int i =0; i < N; i++) cout << A[i] << ((i == N-1)?"\n":" ");
    return 0;}
        
// look at my code
// my code is amazing