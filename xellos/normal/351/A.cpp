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
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    int N,I =0;
    cin >> N;
    double sum =0;
    vector<double> V(2*N);
    for(int i =0; i < 2*N; i++) {
        cin >> V[i];
        V[i] -=(int)V[i];
        if(V[i] < -soclose) V[i] +=1;
        if(abs(V[i]) < soclose) I++;
        sum +=V[i];}
    double ans =2*N;
    for(int i =0; i <= I; i++) {
        // i celych zaokruhlim nahor
        // I-i celych nadol
        if(I-i > N || i > N) continue;
        ans =min(ans,abs(N-i-sum));}
    cout << fixed << setprecision(3) << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing