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

const ll p1 = 2102311, p2 = 91284131, m1 = 1001433997, m2 = 1e9+33;
const int maxn = 1000005;
ll pw1[maxn],lh1[maxn],pw2[maxn],lh2[maxn];
void init(string s) {
    int n = s.size();
    pw1[0]=pw2[0]=1,lh1[1]=lh2[1]=0;
    for(int i=1;i<=n;++i) pw1[i]=pw1[i-1]*p1%m1,pw2[i]=pw2[i-1]*p2%m2;
    for(int i=1;i<=n;++i) lh1[i]=(lh1[i-1]*p1+s[i-1])%m1,lh2[i]=(lh2[i-1]*p2+s[i-1])%m2;
}
inline ll get1(int i, int j) {return ((lh1[j]-lh1[i-1]*pw1[j-i+1])%m1+m1)%m1;}
inline ll get2(int i, int j) {return ((lh2[j]-lh2[i-1]*pw2[j-i+1])%m2+m2)%m2;}

int cnt[1000005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int K = k;
        string s;
        cin >> s;
        cnt[0] = 0;
        for(int i=1;i<=s.size();++i) {
            cnt[i] = cnt[i-1] + (s[i-1] == '0');
        }
        init(s);
        unordered_map<ll, int> mp1, mp2;
        string pre = string(max(k - 25, 0), '0');
        k = min(k, 25);
        while((1<<k) > n*2) --k, pre += '0';
        for(int i = K; i <= n; ++i) {
            if(cnt[i - K] == cnt[i - k]) {
                mp1[get1(i - k + 1, i)] = 1;
                mp2[get2(i - k + 1, i)] = 1;
            }
        }
        int ok = 0;
        string ans;
        for(int i = 0; i < 1 << k; ++i) {
            ll tmp1 = 0, tmp2 = 0;
            for(int j = k - 1; j >= 0; --j) {
                tmp1 = (tmp1 * p1 + (i >> j & 1 ^ 1) + '0') % m1;
                tmp2 = (tmp2 * p2 + (i >> j & 1 ^ 1) + '0') % m2;
            }
            if(!mp1.count(tmp1) || !mp2.count(tmp2)) {
                ok = 1;
                cout << "YES\n";
                cout << pre;
                ans += pre;
                for(int j = k - 1; j >= 0; --j) {
                    ans += (i >> j & 1) + '0';
                    cout << (i >> j & 1);
                }
                cout << '\n';
                break;
            }
        }
        if(!ok) cout << "NO\n";
    }
}