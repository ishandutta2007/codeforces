#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll cnt[20][2][2][1<<11], sm[20][2][2][1<<11], l, r, k, pw[20]={1};
string s;
inline ll cntbits(ll wtf){
        ll res = 0;
        while(wtf){
                res ++;
                wtf -= (wtf&-wtf);
        }
        return res;
}
ll solve(ll d,ll z,ll m,ll msk){
        if(d==s.size()) return cntbits(msk)<=k;
        else if(cnt[d][z][m][msk]!=-1) return cnt[d][z][m][msk];
        cnt[d][z][m][msk] = 0;
        for(int i=0;i<=(m?s[d]-'0':9);i++){
                if(i==0&&z){
                        cnt[d][z][m][msk] = (cnt[d][z][m][msk]+solve(d+1,1,0,msk))%mod;
                        sm[d][z][m][msk] = (sm[d][z][m][msk]+sm[d+1][1][0][msk])%mod;
                }
                else{
                        cnt[d][z][m][msk] = (cnt[d][z][m][msk]+solve(d+1,0,i==s[d]-'0'&&m,msk|(1<<i)))%mod;
                        sm[d][z][m][msk] = (sm[d][z][m][msk]+solve(d+1,0,i==s[d]-'0'&&m,msk|(1<<i))*i%mod*pw[s.size()-d-1]%mod)%mod;
                        sm[d][z][m][msk] = (sm[d][z][m][msk]+sm[d+1][0][i==s[d]-'0'&&m][msk|(1<<i)])%mod;
                }
        }
        return cnt[d][z][m][msk];
}
int main(){
        scanf("%lld%lld%lld",&l,&r,&k);
        s = to_string(r);
        for(int i=1;i<20;i++) pw[i]=(pw[i-1]*10)%mod;
        memset(cnt,-1,sizeof(cnt));
        solve(0,1,1,0); ll ans = sm[0][1][1][0];
        s = to_string(l-1);
        memset(cnt,-1,sizeof(cnt));
        memset(sm, 0, sizeof(sm));
        solve(0,1,1,0); ans -= sm[0][1][1][0];
        if(ans<0) ans += mod;
        printf("%lld\n",ans);
        return 0;
}