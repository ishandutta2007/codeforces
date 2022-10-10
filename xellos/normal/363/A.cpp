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
    int N;
    cin >> N;
    int b =0;
    while(N > 0 || b == 0) {
        int c =N%10;
        b++;
        N /=10;
        if(c/5 > 0) {
            cout << "-O|";
            c -=5;}
        else cout << "O-|";
        for(int i =0; i < c; i++) cout << "O";
        cout << "-";
        for(int i =0; i < 4-c; i++) cout << "O";
        cout << "\n";}
    return 0;}
        
// look at my code
// my code is amazing