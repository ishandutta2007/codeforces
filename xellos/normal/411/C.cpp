// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int A[4];
    int B[4];
    for(int i =0; i < 4; i++) cin >> A[i] >> B[i];
    for(int i =0; i < 2; i++) {
        swap(A[0],A[1]);
        swap(B[0],B[1]);
        bool winF =true;
        for(int j =0; j < 2; j++) {
            swap(A[2],A[3]);
            swap(B[2],B[3]);
            if(A[2] >= B[0] || B[3] >= A[1]) winF =false;}
        if(winF) {
            cout << "Team 1\n"; 
            return 0;}
        }
    for(int i =0; i < 2; i++) {
        swap(A[0],A[1]);
        swap(B[0],B[1]);
        bool draw =true;
        for(int j =0; j < 2; j++) {
            swap(A[2],A[3]);
            swap(B[2],B[3]);
            if(A[2] > B[0] && B[3] > A[1]) draw =false;}
        if(draw) {
            cout << "Draw\n"; 
            return 0;}
        }
    cout << "Team 2\n";
    return 0;}
    
// look at my code
// my code is amazing