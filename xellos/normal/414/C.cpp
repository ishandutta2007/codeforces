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
    
struct fin {
    vector<int> T;
    fin(int N) {T.resize(N+patkan,0);}
    
    int lastone(int x) {return x&(x^(x-1));}
    
    int get(int pos) {
        int ret =0;
        for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
        return ret;}
    
    void put(int pos, int val) {
        for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;
        }
    };
    
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int N =1<<n;
    map<int,int> a;
    vector<int> A(N);
    for(int i =0; i < N; i++) {
        cin >> A[i];
        a[A[i]] =0;}
    int x =0;
    ALL_THE(a,it) it->ss =x++;
    for(int i =0; i < N; i++) A[i] =a[A[i]];
    
    vector<long long> I(n+1,0);
    vector<long long> Ii(n+1,0);
    fin F(N);
    vector<int> P(N+1,0);
    for(int k =1; k <= n; k++) {
        int n0 =1<<(k-1), k0 =N/(1<<k);
        for(int j =0; j < k0; j++) {
            for(int i =n0-1; i >= 0; i--) {
                F.put(A[2*n0*j+n0+i],1);
                P[A[2*n0*j+n0+i]]++;}
            for(int i =n0-1; i >= 0; i--) {
                I[k] +=F.get(A[2*n0*j+i]-1);
                Ii[k] -=P[A[2*n0*j+i]];}
            for(int i =n0-1; i >= 0; i--) {
                F.put(A[2*n0*j+n0+i],-1);
                P[A[2*n0*j+n0+i]]--;}
            }
        Ii[k] +=1LL*n0*k0*n0-I[k];}

    vector<bool> R(n+1,false);
    int Q;
    cin >> Q;
    for(int q =0; q < Q; q++) {
        int v; 
        cin >> v;
        R[v] =!R[v];
        bool r =false;
        long long Ia =0;

        for(int i =n; i >= 0; i--) {
            r =r^R[i];
            if(r) Ia +=Ii[i];
            else Ia +=I[i];}

        cout << Ia << "\n";}
    return 0;}
        
// look at my code
// my code is amazing