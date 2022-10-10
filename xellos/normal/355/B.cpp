#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for(int i =0; i < 4;i++) cin >> a[i];
    int ans =min(2*a[2],a[3]), N,M,b, costB =0, costT =0;
    cin >> N >> M;
    for(int i =0; i < N; i++) {
        cin >> b;
        b =min(b*a[0],a[1]);
        costB +=b;}
    for(int i =0; i < M; i++) {
        cin >> b;
        b =min(b*a[0],a[1]);
        costT +=b;}
    ans =min(ans,costB+costT);
    ans =min(ans,a[2]+min(costB,costT));
    cout << ans << "\n";
    return 0;}