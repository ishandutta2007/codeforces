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
    int N,M;
    cin >> N >> M;
    long long mod =1000000007;
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
    vector< vector<long long> > zac(N+1,vector<long long>(101,0));
    vector< vector< pair<int,int> > > kon(N+1);
    for(int i =0; i < M; i++) {
        int k,l,r;
        cin >> l >> r >> k;
        zac[l-1][k]++;
        kon[r].push_back(make_pair(k,l-1));}

    vector< vector<long long> > C(N+1+101,vector<long long>(101,0));
    for(int i =0; i <= N+101; i++) {
        C[i][0] =1;
        for(int j =1; j <= min(100,i); j++) C[i][j] =(C[i-1][j-1]+C[i-1][j])%mod;}

    vector<long long> X(101,0);
    for(int i =0; i < N; i++) {
        vector<long long> Y =zac[i];
        int a =0;
        for(int j =100; j >= 0; j--) {
            a =(a+X[j])%mod;
            Y[j] =(Y[j]+a)%mod;}
        X =Y;
        ALL_THE(kon[i],it) for(int j =0; j <= (*it).ff; j++)
            X[j] =(X[j]-C[i-(*it).ss-1+(*it).ff-j][(*it).ff-j])%mod;
        for(int j =100; j >= 0; j--) A[i] =(A[i]+X[j])%mod;
        if(A[i] < 0) A[i] +=mod;
        cout << A[i] << ((i == N-1)?"\n":" ");}
    return 0;}
        
// look at my code
// my code is amazing