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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int w=0;
        for(char c:s) if(c=='W') w++;
        vector<int> p;
        for(int i=0;i<n;++i) if(s[i]=='W') p.push_back(i);
        vector<pair<int,int>> vs;
        for(int i=1;i<p.size();++i) {
            vs.push_back({p[i-1]+1, p[i]-1});
        }
        sort(all(vs),[&](pii a,pii b) {
            return a.second-a.first<b.second-b.first;
        });
        for(auto &pr : vs) {
            int l=pr.first,r=pr.second;
            if(l>r) continue;
            for(int i=l;i<=r;++i) {
                if(!k) break;
                assert(s[i] == 'L');
                s[i]='W';
                --k;
            }
            if(!k) break;
        }
//        cout << s << endl;
        int ans=0;
        if(k) {
            for(int i=0;i<s.size();++i) {
                if(s[i] == 'W') {
                    for(int j=i-1;k && j>=0;--j) {
                        if(s[j] == 'L') {
                            s[j] = 'W';
                            --k;
                        } else break;
                    }
                    for(int j=i+1;k && j<s.size();++j) {
                        if(s[j] == 'L') {
                            s[j] = 'W';
                            --k;
                        }else break;
                    }
                }
                if(!k) break;
            }
        }
        for(int i=0;i<s.size();++i) {
            if(k && s[i] == 'L') {
                --k;
                s[i] = 'W';
            }
            if(s[i] == 'W') {
                ++ans;
                if(i && s[i-1] == 'W') ++ans;
            }
        }
        cout<<ans<<endl;
    }
}