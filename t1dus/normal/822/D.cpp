#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
ll t,l,r,ans[5000005],sp[5000005],res = 0, cur = 1,INF = 1e9,MOD = (1e9)+7;
signed main() {
	REP(i,5000005) sp[i] = i;
	for(int i = 2; i < 5000005; i ++) if (sp[i] == i) for(int j = i*i; j < 5000005; j+= i) if (sp[j] == j) sp[j] = i;
	ans[1] = 0;
	FOR(i,2,5000005)ans[i] = (((i*(sp[i]-1))/2)%MOD + ans[i/sp[i]])%MOD;
    cin >> t >> l >> r;
    FOR(i,l,r+1){
        res = (res+((ans[i]*cur)%MOD))%MOD;
        cur = (cur*t)%MOD;
    }
    cout << res << endl;
}