#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

ll calc(string s, ll a, ll b) {
    ll aa=0,aa2=0,bb=0,bb2=0;
    for(char c:s) {
        if(c=='0') aa++;
        if(c=='1') aa2+=aa;

        if(c=='1') bb++;
        if(c=='0') bb2+=bb;

    }
    return aa2*a+bb2*b;
}
int mk[200005];
int main() {
    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    ll ans = 8e18;
    {
        string t = s;
        for(int i=0;i<s.size();++i) {
            if(t[i] == '?') {
                t[i] = '0';
                mk[i] = 1;
            }
        }
        ll tmp = calc(t, a, b);
        ans = min(ans, tmp);
        ll cnt0=0,cnt1=0;
        for(char c:t)if(c=='0') cnt0++;else cnt1++;
        ll l0=0,l1=0;
        for(int i=0;i<t.size();++i) {
            if(t[i] == '1') cnt1--;
            else cnt0--;
            if(mk[i]) {
                assert(t[i] == '0');
                t[i] = '1';
                tmp += l0 * a + cnt0 * b;
                tmp -= l1 * b + cnt1 * a;
                ans = min(ans, tmp);
            }
            if(t[i] == '1') l1++;
            else l0++;
        }
    }
    {
        string t = s;
        for(int i=0;i<s.size();++i) {
            if(t[i] == '?') {
                t[i] = '1';
                mk[i] = 1;
            }
        }
        ll tmp = calc(t, a, b);
        ans = min(ans, tmp);
        ll cnt0=0,cnt1=0;
        for(char c:t)if(c=='0') cnt0++;else cnt1++;
        ll l0=0,l1=0;
        for(int i=0;i<t.size();++i) {
            if(t[i] == '1') cnt1--;
            else cnt0--;
            if(mk[i]) {
                assert(t[i] == '1');
                t[i] = '0';
                tmp -= l0 * a + cnt0 * b;
                tmp += l1 * b + cnt1 * a;
                ans = min(ans, tmp);
            }
            if(t[i] == '1') l1++;
            else l0++;
        }
    }
    cout<<ans<<endl;
}