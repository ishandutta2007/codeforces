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


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=1e9,aa,bb,cc;
        for(int i=1;i<=20000;++i) {
            // try b = i
            int disa = 1e9, besta, bestc, cnt = abs(i-b);
            if(c % i < i - c % i) {
                cnt += c % i;
                bestc = c - c % i;
            } else {
                cnt += i - c % i;
                bestc = c + i - c % i;
            }
            assert(bestc % i == 0);
            for(int j=1;j*j<=i;++j) {
                if(i % j == 0) {
                    // try a = j
                    if(abs(a - j) < disa) {
                        disa = abs(a - j);
                        besta = j;
                    }
                    // try a = i / j
                    if(abs(a - i / j) < disa) {
                        disa = abs(a - i / j);
                        besta = i / j;
                    }
                }
            }
            cnt += disa;
            if(cnt < ans) {
                ans = cnt;
                aa = besta;
                bb = i;
                cc = bestc;
            }
        }
        cout << ans << "\n" << aa << " " << bb << " " << cc << endl;
    }
}