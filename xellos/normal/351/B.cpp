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
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i =0; i < N; i++) cin >> P[i];
    int I =0;
    for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
        if(P[i] > P[j]) I++;
    
    cout << (int)(I%2 != 0)+4*(I/2) << ".000000000\n";
    return 0;}
        
// look at my code
// my code is amazing