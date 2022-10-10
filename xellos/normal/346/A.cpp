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
    
long long GCD(long long a, long long b) {
    if(a > b) swap(a,b);
    if(a == 0) return b;
    return GCD(b%a,a);}
    
int main() {
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
    long long m =A[0], d =A[0];
    for(int i =0; i < N; i++) {
        d =GCD(d,A[i]);
        m =max(m,A[i]);}
    
    if((m/d-N)%2 == 0) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;}
        
// look at my code
// my code is amazing