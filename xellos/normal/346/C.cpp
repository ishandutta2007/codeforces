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
    int N,A,B;
    cin >> N;
    vector<int> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    sort(V.begin(),V.end());
    cin >> A >> B;
    
    vector<int> go(1000000+tisic,1);
    for(int i =0; i < N; i++) if(i == 0 || V[i] != V[i-1]) {
        int x =B/V[i]+1, y =A/V[i];
        if(B%V[i] != 0) x++;
        for(int j =x; j <= y; j++) go[j*V[i]-B-1] =max(go[j*V[i]-B-1],V[i]-1);
        if(A%V[i] <= A-B) go[A-B] =max(go[A-B],A%V[i]);}
    for(int i =1000000; i >= 0; i--) go[i] =max(go[i],go[i+1]-1);
    
    int ans =0, akt =A-B;
    while(akt > 0) {
        ans++;
        akt -=go[akt];}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing