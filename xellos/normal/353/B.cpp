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
    int N,a;
    cin >> N;
    vector<int> poc(100);
    vector<int> V(2*N);
    vector< vector<int> > pos(100);
    for(int i =0; i < 2*N; i++) {
        cin >> a;
        V[i] =a;
        pos[a].push_back(i);
        poc[a]++;}
    
    int ansA =0, ansB =0;
    vector<int> S(2*N);
    for(int i =0; i < 100; i++) if(poc[i] > 1) {
        ansA++, ansB++;
        S[pos[i][0]] =0;
        S[pos[i][1]] =1;}
    for(int i =0; i < 100; i++) if(poc[i] == 1) {
        if(ansA < ansB) {ansA++; S[pos[i][0]] =0;}
        else {ansB++; S[pos[i][0]] =1;}}
    cout << ansA*ansB << "\n";

    for(int i =0; i < 100; i++) for(int j =2; j < poc[i]; j++) {
        if(ansA < N) {ansA++; S[pos[i][j]] =0;}
        else {ansB++; S[pos[i][j]] =1;}}
    for(int i =0; i < 2*N; i++) cout << S[i]+1 << ((i == 2*N-1)?"\n":" ");
    return 0;}
        
// look at my code
// my code is amazing