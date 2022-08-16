#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)

#define int long long

const int MX = 3605;
const int MOD = 998244353;

int h,w,m;
int row[MX],col[MX];
int ncr[MX][MX],fact[MX];
int dpr[MX][MX],dpc[MX][MX];

signed main(){
    cin >> h >> w >> m;
    REP(i,m){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        row[x1] = 1;
        row[x2] = 1;
        col[y1] = 1;
        col[y2] = 1;
    }
    ncr[0][0] = 1;
    fact[0] = 1;
    FOR(i,1,MX){
        fact[i] = (fact[i-1]*i)%MOD;
        ncr[i][0] = 1;
        FOR(j,1,i+1){
            ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%MOD; 
        }
    }
    int valh = 0,valw = 0;
    FOR(i,1,h+1) valh += 1-row[i];
    FOR(i,1,w+1) valw += 1-col[i];
    dpr[0][0] = 1;
    dpc[0][0] = 1;
    FOR(i,1,h+1){
        dpr[i][0] = 1;
        FOR(j,1,i+1){
            if(i == 1 or row[i] or row[i-1]) dpr[i][j] = dpr[i-1][j];
            else dpr[i][j] = (dpr[i-1][j]+dpr[i-2][j-1])%MOD;
        }
    }
    FOR(i,1,w+1){
        dpc[i][0] = 1;
        FOR(j,1,i+1){
            if(i == 1 or col[i] or col[i-1]) dpc[i][j] = dpc[i-1][j];
            else dpc[i][j] = (dpc[i-1][j]+dpc[i-2][j-1])%MOD;
        }
    }
    int ans = 0;
    REP(dh,h+1){
        REP(dv,w+1){
            if(h-dh-2*dv < 0 or w-dv-2*dh < 0) continue;
            int cur = (dpr[h][dv]*dpc[w][dh])%MOD;
            cur = (cur*ncr[valh-2*dv][dh])%MOD;
            cur = (cur*ncr[valw-2*dh][dv])%MOD;
            cur = (cur*fact[dv])%MOD;
            cur = (cur*fact[dh])%MOD;
            ans = (ans+cur)%MOD;
            // cout << dh << " " << dv << " " << ans << "\n";

        }
    }
    cout << ans << "\n";
}