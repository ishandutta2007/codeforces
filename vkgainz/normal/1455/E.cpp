#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 2e5+5;
long long solve(pair<int, int> p[]) {
    //ld, lu, rd, ru
    int x[4], y[4];
    for(int i=0;i<4;i++) {
        x[i] = p[i].f;
        y[i] = p[i].s;
    }
    int mxX = max(x[2], x[3])-min(x[0], x[1]);
    int mnX = max(0, min(x[2], x[3])-max(x[0], x[1]));
    //check 0 case?
    int mxY = max(y[1], y[3])-min(y[0], y[2]);
    int mnY = max(0, min(y[1], y[3])-max(y[0], y[2]));
    if(mxX<0 || mxY<0) //check this
        return 2e9;
    int intersection = min(mxX, mxY)-max(mnX, mnY); 
    return (long long) abs(x[2]-x[3])+abs(x[0]-x[1])+abs(y[1]-y[3])+abs(y[0]-y[2])+2*max(0, -intersection); //check this
    
}
int main() {
    int t; cin >> t;
    while(t--) {
        pair<int, int> p[4];
        for(int i=0;i<4;i++)
            cin >> p[i].f >> p[i].s;
        sort(p, p+4);
        long long ans = solve(p);
        while(next_permutation(p, p+4)) {
            ans = min(ans, solve(p));
        }
        cout << ans << "\n";
    }
}