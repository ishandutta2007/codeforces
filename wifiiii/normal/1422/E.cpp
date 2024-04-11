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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;


string pre[100005];
int presz[100005],f[100005],prelst[100005],prelstidx[100005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<pair<int,int>> v;
    int cnt = 0, lst = -1;
    for(char c : s) {
        if(c == lst) ++cnt;
        else {
            if(cnt) v.push_back({lst, cnt});
            lst = c;
            cnt = 1;
        }
    }
    v.push_back({lst, cnt});
    reverse(all(v));
    int n = s.size();
    int j=0,len=1;
    int last = 0;
    vector<string> anss;
    vector<int> anss2;
    for(int i=0;i<n;++i,++len) {
        if(len > v[j].second) {
            len -= v[j].second;
            int tmplen = v[j].second;
            if(v[j].first > last) f[j] = 1, tmplen %= 2;
            else if(v[j].first == last) {
                f[j] = f[prelstidx[j-1]];
            }
            if(f[j]) tmplen %= 2;
            if(v[j].second & 1) {
                last = v[j].first;
                prelstidx[j] = j;
            }
            else {
                last = min(last, v[j].first);
                if(v[j].first > last) prelstidx[j] = prelstidx[j-1];
                else prelstidx[j] = j;
            }
            prelst[j] = last;
            pre[j] = string(tmplen, v[j].first) + (j?pre[j-1]:"");
            if(pre[j].size() > 10) pre[j] = pre[j].substr(0, 5) + pre[j].substr(pre[j].size()-5);
            presz[j] = (j?presz[j-1]:0) + tmplen;
            ++j;
        }
        int anslen = len, sz = 0;
        if(v[j].first > last || (v[j].first == last && f[prelstidx[j-1]])) anslen = len & 1;
        sz += anslen;
        string tmp = string(min(10, anslen), v[j].first);
        if(j) tmp += pre[j-1], sz += presz[j-1];
        if(sz > 10) anss.push_back(tmp.substr(0, 5) + "..." + tmp[tmp.size()-2] + tmp.back());
        else anss.push_back(tmp);
        anss2.push_back(sz);
    }
    reverse(all(anss));
    reverse(all(anss2));
    for(int i=0;i<anss.size();++i) {
        cout << anss2[i] << " " << anss[i] << "\n";
    }
}