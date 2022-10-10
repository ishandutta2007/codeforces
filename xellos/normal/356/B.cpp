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
    
long long gcd(long long a, long long b) {
    if(a > b) swap(a,b);
    if(a == 0) return b;
    return gcd(b%a,a);}
    
int main() {
    cin.sync_with_stdio(0);
    long long N,M;
    cin >> N >> M;
    string x,y;
    cin >> x >> y;
    long long d =gcd(x.length(),y.length());
    int L =x.length(), K =y.length();
    
    long long ans =L*N;
        vector<long long> pocX(26,0);
    vector<long long> pocY(26,0);
    long long h =0;
    for(int i =0; i < d; i++) {
        // toto modulo
        int a =i;
        while(a < L) {
            pocX[x[a]-'a']++;
            a +=d;}
        a =i;
        while(a < K) {
            pocY[y[a]-'a']++;
            a +=d;}
        a =i;
        while(a < L) {
            h +=pocX[x[a]-'a']*pocY[x[a]-'a'];
            pocX[x[a]-'a'] =0;
            a +=d;}
        a =i;
        while(a < K) {
            pocY[y[a]-'a'] =0;
            a +=d;}
        }
    long long rep =N/(K/d);
    cout << ans-h*rep << "\n";
    return 0;}
        
// look at my code
// my code is amazing