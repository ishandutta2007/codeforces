#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
typedef pair<int,int> pii;

typedef unsigned long long ull;
ull magic[1000005];
ll ans = 0;
int a[500005], cnt[500005], lft[500005], vis[500005], n;
ull aa[500005];
void solve(int l,int r) {
    if(r-l<=1) return;
    int m=(l+r)/2;
    solve(l,m);
    solve(m+1,r);
    ull cur = 0;
    unordered_map<ull,int> mp;
    int tmp = l;
    for(int i=m;i>=l;--i) {
        if(cnt[a[i]] > 2) {tmp = i+1; break;}
        cnt[a[i]]++;
        if(cnt[a[i]] == 3) {
            cur -= magic[a[i]+n];
        } else if(cnt[a[i]] == 2) {
            cur += magic[a[i]+n]-magic[a[i]];
        } else {
            cur += magic[a[i]];
        }
        aa[i] = cur;
        mp[cur]++;
    }
    for(int i=tmp;i<=m;++i) cnt[a[i]]--;
    int tmp2 = r;
    cur = 0;
    for(int i=m+1;i<=r;++i) {
        cnt[a[i]]++;
        if(cnt[a[i]] > 3) {
            tmp2 = i;
            break;
        }
        else if(cnt[a[i]] == 1) {
            cur += magic[a[i]+n];
        } else if(cnt[a[i]] == 2) {
            cur += magic[a[i]]-magic[a[i]+n];
        } else {
            cur -= magic[a[i]];
            int pos = lft[lft[lft[i]]];
            if(pos >= l && pos <= m) {
                while(tmp <= pos) {
                    mp[aa[tmp]]--;
                    ++tmp;
                }
            }
        }
        ans += mp[cur];
    }
    for(int i=m+1;i<=tmp2;++i) cnt[a[i]]--;
}
int main() {
    cin >> n;
    for(int i=0;i<=2*n;++i) magic[i]=mrand();
    ii cin >> a[i];
    for(int i=1;i<=n;++i) {
        lft[i] = vis[a[i]];
        vis[a[i]] = i;
    }
    solve(1, n);
    cout << ans << endl;
}