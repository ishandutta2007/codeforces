#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int lim = 1e6+2;
const int maxn = lim*2;
const int mod = 1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
ll sz[100005], ans[100005], pw[100005], rpw[100005];
int f[maxn];
void getf(string s) {
    f[0] = 0;
    for(int i=1;i<s.size();++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = j + 1;
        else f[i] = 0;
    }
}
int kmp(string s, string t) {
    int i = 0, j = 0, ret = 0;
    while(i < s.size()) {
        if(s[i] == t[j]) {
            ++i, ++j;
            if(j == t.size()) {
                j = f[j-1];
                ++ret;
            }
        } else {
           if(!j) ++i;
           else j=f[j-1];
        }
    }
    return ret;
}
const ll Mod[2] = {1000000009, 998244353};
const ll P[2] = {131, 13331};
ll Pw[2][maxn], pre[26][100005];
struct StringHash{
    vector<vector<ll>> lh;
    int n;
    void init(string s) {
        n = s.size();
        lh.resize(2,vector<ll>(n+1));
        for(int j=0;j<2;++j) {
            lh[j][1]=0;
            for(int i=1;i<=n;++i) lh[j][i]=(lh[j][i-1]*P[j]+s[i-1])%Mod[j];
        }
    }
    pair<ll,ll> getl(int i, int j) {
        return {((lh[0][j]-lh[0][i-1]*Pw[0][j-i+1])%Mod[0]+Mod[0])%Mod[0],
                ((lh[1][j]-lh[1][i-1]*Pw[1][j-i+1])%Mod[1]+Mod[1])%Mod[1]};
    }
};

string S[1005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pw[0]=rpw[0]=1;
    ll inv2=(mod+1)/2;
    for(int i=1;i<=100000;++i) {
        pw[i]=pw[i-1]*2%mod;
        rpw[i]=rpw[i-1]*inv2%mod;
    }
    for(int j=0;j<2;++j) {
        Pw[j][0]=1;
        for(int i=1;i<maxn;++i) Pw[j][i]=Pw[j][i-1]*P[j]%Mod[j];
    }
    int n, Q;
    cin >> n >> Q;

    string s, t;
    cin >> s >> t;
    sz[0] = s.size();
    int sztp=0;
    for(int i=1;i<=n;++i) {
        sz[i]=sz[i-1]*2+1;
        if(i==n || sz[i]>1e9) {
            sztp=i;
            break;
        }
    }
    S[0] = s;
    StringHash sh;
    int ms=0,msz=0;
    for(int i=1;i<=n;++i) {
        S[i] = S[i-1] + t[i-1] + S[i-1];
        if(i == n || S[i].size() >= lim) {
            ms = i;
            msz = S[i].size();
            sh.init(S[i]);
            break;
        }
    }
    for(int j=0;j<26;++j) {
        ll tmp=0;
        for(int i=1;i<=n;++i) {
            pre[j][i]=pre[j][i-1];
            if(t[i-1]-'a' == j) (pre[j][i]+=pw[n-i])%=mod;
        }
    }
    for(int i=1;i<=Q;++i) {
        int k;
        string p;
        cin >> k >> p;
        if(k <= sztp && sz[k] < p.size()) {
            cout << 0 << '\n';
            continue;
        }
        StringHash sh2;
        sh2.init(p);
        getf(p);
        int pos = lower_bound(sz, sz+sztp, (int)p.size()) - sz;
        ll tmp1 = kmp(S[pos], p) * pw[k-pos] % mod;

        for(int j = 0; j < p.size(); ++j) {
            if(sh2.getl(1, j) == sh.getl(msz-j+1, msz)
            && sh2.getl(j+2, p.size()) == sh.getl(1, p.size()-j-1)) {
                tmp1 += (pre[p[j]-'a'][k] - pre[p[j]-'a'][pos]) * rpw[n-k] % mod;
            }
            // [1, j] = [S.size() - j + 1, S.size()]
            // [j + 2, p.size()] = [1, p.size() - j - 1]
            // p[j] == s[r], pos+1 <= r <= k begin with 1.
            // ans += fpow(2, k - r)
        }
        tmp1 %= mod;
        if(tmp1 < 0) tmp1 += mod;
        cout << tmp1 << '\n';
    }
}