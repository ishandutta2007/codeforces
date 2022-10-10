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
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    int N,M,a;
    cin >> N >> M; N--;
    vector<int> C(M);
    for(int i =0; i < M; i++) cin >> a >> C[i];
    sort(C.begin(),C.end());
    
    int ansE =(int)floor(sqrt(2+2*N));
    if(ansE%2 != 0) ansE--;

    int ansO =(int)floor(0.5+sqrt(0.25+2*N));
    if(ansO%2 == 0) ansO--;

    int ans =min(M,max(ansO,ansE));
    long long ansC =0;
    for(int i =M-1; i >= M-ans; i--) ansC +=C[i];
    cout << ansC << "\n";
    return 0;}
        
// look at my code
// my code is amazing