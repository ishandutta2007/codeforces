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
    
bool pos(int N, int K, long long C, vector<long long> A) {
    vector<long long> X(N,K+1);
    // X[i]: kolko najmenej musim zmenit z [1,i-1] aby [0,i] bol dobry?
    for(long long i =0; i < N; i++) {
        // vsetky predtym zmenene
        X[i] =i;
        for(long long j =0; j < i; j++) // posledny nezmeneny
            if(abs(A[i]-A[j]) <= C*(i-j)) X[i] =min(X[i],X[j]+i-j-1);
        // musim za tym este daco menit?
        bool b =true;
        for(int j =i+1; j < N; j++) if(abs(A[j]-A[j-1]) > C) b =false;
        if(b && X[i] <= K) return true;
        // je za tym daco nezmenene?
        if(X[i]+(N-i-1) <= K) return true;}
    return false;}

int main() {
    cin.sync_with_stdio(0);
    int N,K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
    
    if(N < 2) {cout << "0\n"; return 0;}
    long long Ca =-1, Cb =2000000000;
    while(Cb > Ca+1) {
        long long C =(Ca+Cb)/2;
        if(pos(N,K,C,A)) Cb =C;
        else Ca =C;}
    cout << Cb << "\n";
    return 0;}
        
// look at my code
// my code is amazing