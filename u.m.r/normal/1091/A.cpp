#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    int y, b, r;
    cin >> y >> b >> r;
    r -= 2;
    b -= 1;
    int u = min(min(y, b), r);
    cout << u * 3 + 3 << endl;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}