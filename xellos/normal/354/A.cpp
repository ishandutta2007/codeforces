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
    long long L,R,Ql,Qr;
    cin >> N >> L >> R >> Ql >> Qr;
    vector<long long> W(N);
    for(int i =0; i < N; i++) cin >> W[i];
    vector<long long> S(N+1,0);
    for(int i =0; i < N; i++) S[i+1] =S[i]+W[i];
    
    long long ans =min((N-1)*Qr+R*S[N],(N-1)*Ql+L*S[N]);
    for(int i =0; i < N; i++) {
        // 0..i lavou, zvysne pravou
        // i+1 > N-i-1: LPLPLP...LPLLLL, cena Ql*(i+1-(N-i))
        // i+1 < N-i-1: cena Qr*(N-2i-1)
        if(i+1 == N-i-1) ans =min(ans,S[i+1]*L+(S[N]-S[i+1])*R);
        if(i+1 > N-i-1) ans =min(ans,S[i+1]*L+(S[N]-S[i+1])*R+Ql*(2*i+1-N));
        if(i+1 < N-i-1) ans =min(ans,S[i+1]*L+(S[N]-S[i+1])*R+Qr*(N-2*i-3));}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing