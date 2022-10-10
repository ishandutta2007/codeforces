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
    int N,ans =0;
    cin >> N;
    vector< pair<int,int> > V(N);
    for(int i =0; i < N; i++) {
        cin >> V[i].ff >> V[i].ss;
        if(V[i].ff == 0 || V[i].ss == 0) ans +=4;
        else ans +=6;}
    cout << ans << "\n";
    sort(V.begin(),V.end());
    
    for(int i =0; i < N; i++) if((V[i].ff == 0 || V[i].ss == 0) && V[i].ff+V[i].ss > 0) {
        cout << "1 ";
        if(V[i].ff > 0) cout << V[i].ff << " R\n2\n1 " << V[i].ff << " L\n3\n";
        else cout << V[i].ss << " U\n2\n1 " << V[i].ss << " D\n3\n";}
    for(int i =N-1; i >= 0; i--) if((V[i].ff == 0 || V[i].ss == 0) && V[i].ff+V[i].ss < 0) {
        cout << "1 ";
        if(V[i].ff < 0) cout << -V[i].ff << " L\n2\n1 " << -V[i].ff << " R\n3\n";
        else cout << -V[i].ss << " D\n2\n1 " << -V[i].ss << " U\n3\n";}
    
    for(int i =0; i < N; i++) if(V[i].ff != 0 && V[i].ss > 0) {
        if(V[i].ff > 0) cout << "1 " << V[i].ff << " R\n";
        else cout << "1 " << -V[i].ff << " L\n";
        cout << "1 " << V[i].ss << " U\n2\n";
        cout << "1 " << V[i].ss << " D\n";
        if(V[i].ff > 0) cout << "1 " << V[i].ff << " L\n3\n";
        else cout << "1 " << -V[i].ff << " R\n3\n";}
    for(int i =N-1; i >= 0; i--) if(V[i].ff != 0 && V[i].ss < 0) {
        if(V[i].ff > 0) cout << "1 " << V[i].ff << " R\n";
        else cout << "1 " << -V[i].ff << " L\n";
        cout << "1 " << -V[i].ss << " D\n2\n";
        cout << "1 " << -V[i].ss << " U\n";
        if(V[i].ff > 0) cout << "1 " << V[i].ff << " L\n3\n";
        else cout << "1 " << -V[i].ff << " R\n3\n";}
    return 0;}
        
// look at my code
// my code is amazing