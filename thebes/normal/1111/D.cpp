#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e5+5, MM = 52, mod = 1e9+7;
int n, m, i, j, k, x, y, ans[MN], sz[60], dp[MN], fac[MN], coef, ans2[60];
vector<pii> qu[60];
string s;

int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

int main(){
    cin >> s; n = s.size();
    for(char c : s){
        if(c>='a'&&c<='z') sz[c-'a']++;
        else sz[c-'A'+26]++;
    }
    fac[0] = 1;
    for(i=1;i<=n;i++) fac[i]=(1LL*fac[i-1]*i)%mod;
    coef = 1LL*fac[n/2]*fac[n/2]%mod;
    for(i=0;i<MM;i++)
        coef=1LL*coef*qpow(fac[sz[i]],mod-2)%mod;
    for(scanf("%d",&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        char ch = s[x-1]; int id, idd;
        if(ch>='a'&&ch<='z') id=ch-'a';
        else id=ch-'A'+26;
        ch = s[y-1];
        if(ch>='a'&&ch<='z') idd=ch-'a';
        else idd=ch-'A'+26;
        qu[id].pb({idd,i});
    }
    for(i=0;i<MM;i++){
        if(sz[i]>n/2){
            while(m--) printf("0\n");
            return 0;
        }
    }
    for(i=0;i<MM;i++){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(j=0;j<MM;j++){
            if(i==j||!sz[j]) continue;
            for(k=n/2;k>=sz[j];k--){
                dp[k]+=dp[k-sz[j]];
                if(dp[k]>=mod) dp[k]-=mod;
            }
        }
        for(j=0;j<MM;j++){
            if(i==j||!sz[j]) continue;
            for(k=sz[j];k<=n/2;k++){
                dp[k]-=dp[k-sz[j]];
                if(dp[k]<0) dp[k]+=mod;
            }
            ans2[j]=dp[n/2];
            for(k=n/2;k>=sz[j];k--){
                dp[k]+=dp[k-sz[j]];
                if(dp[k]>=mod) dp[k]-=mod;
            }
        }
        ans2[i] = dp[n/2];
        for(auto v : qu[i]){
            ans[v.second]=2LL*coef*ans2[v.first]%mod;
        }
    }
    for(i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}