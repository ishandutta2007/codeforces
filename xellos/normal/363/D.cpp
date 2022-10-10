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
    
pair<bool,int> kup(int K, int N, int M, int A, vector<int> B, vector<int> P) {
    // prvych K bicyklov, poslednych K deti
    // da sa vsetko z budgetu?
    int S =0;
    for(int i =0; i < K; i++) {
        S +=P[i];
        if(S > A) break;}
    if(S <= A) return make_pair(true,0);
    // da sa to?
    int over =0;
    for(int i =0; i < K; i++) {
        over +=max(0,P[i]-B[N-K+i]);
        if(over > A) break;}
    if(over > A) return make_pair(false,0);
    S =-A;
    for(int i =0; i < K; i++) S +=P[i];
    return make_pair(true,S);}
    
int main() {
    cin.sync_with_stdio(0);
    int N,M,A;
    cin >> N >> M >> A;
    vector<int> B(N);
    for(int i =0; i < N; i++) cin >> B[i];
    sort(B.begin(),B.end());
    vector<int> P(M);
    for(int i =0; i < M; i++) cin >> P[i];
    sort(P.begin(),P.end());
    
    // binsearch vyledku
    int a =0, b =min(M,N)+1, c =0;
    while(b-a > 1) {
        int k =(a+b)/2;
        pair<bool,int> p =kup(k,N,M,A,B,P);
        if(!p.ff) b =k;
        else {
            a =k;
            c =p.ss;}}
    cout << a << " " << c << "\n";
    return 0;}
        
// look at my code
// my code is amazing