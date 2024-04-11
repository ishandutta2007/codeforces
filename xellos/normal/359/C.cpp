// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
using namespace std::tr1;

long long Pow(long long a, long long e, long long mod) {
    if(e <= 0) return 1;
    if(e%2 == 0) {
        long long r =Pow(a,e/2,mod);
        r =(r*r)%mod;
        if(r < 0) r +=mod;
        return r;}
    long long r =(a*Pow(a,e-1,mod))%mod;
    if(r < 0) r +=mod;
    return r;}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin.sync_with_stdio(0);
    int N;
    long long x, S =0;
    cin >> N >> x;
    vector<long long> A(N);
    for(int i =0; i < N; i++) {
        cin >> A[i];
        S +=A[i];}
    
    long long p =S;
    map<long long,long long> B;
    for(int i =0; i < N; i++) B[S-A[i]]++;
    ALL_THE(B,it) {
        long long a =it->ss, pa =it->ff;
        while(a%x == 0) {
            a /=x;
            pa++;}
        auto jt =it; jt++;
        if(jt != B.end() && pa >= jt->ff) B[pa] +=a;
        else p =min(p,pa);}
    
    cout << Pow(x,p,1000000007) << "\n";
    return 0;}
        
// look at my code
// my code is amazing