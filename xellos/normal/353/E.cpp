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
    
int main() {
        cin.sync_with_stdio(0);
    string s; cin >> s;
    int N =s.length();

    vector<int> cons;
    for(int i =0; i < N; i++) if(s[N-1] != s[i]) {
        for(int j =0; j < i; j++) s +=s[j];
        int a =0, b =i;
        for(int j =i; j < s.length(); j++) {
            if(s[j] == s[b]) a++;
            else {
                cons.push_back(a+1);
                a =1;
                b =j;}}
        if(a > 0) cons.push_back(a+1);
        break;}
    
    int ans =0;
    N =cons.size();
//  for(int j =0; j < N; j++) cout << cons[j] << "\n";
    for(int j =0; j < N; j++) if(cons[j] > 2) {
        ans++;
        cons[j] =0;}
    
    for(int j =0; j < N; j++) if(cons[j] == 0) {
        int i =j+1; if(i >= N) i =0;
        if(cons[i] == 0) continue;
        int a =0;
        while(i != j) {
            if(cons[i] == 0) break;
            a++;
            i++; if(i == N) i =0;}
        ans +=a/2;}
    if(ans == 0) ans =cons.size()/2;
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing