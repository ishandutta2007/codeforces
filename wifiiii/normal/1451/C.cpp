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
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        vector<int> a(26),b(26);
        for(char c:s) a[c-'a']++;
        for(char c:t) b[c-'a']++;
        int ok=1;
        for(int i=0;i<26;++i) {
            if(a[i]!=b[i]) {
//                cout << i << " " << a[i] << " " << b[i] << endl;
                if(a[i] < b[i]) {
                    ok=0;
                    break;
                }
                if((a[i]-b[i])%k) {
                    ok=0;
                    break;
                }
                if(i<26) a[i+1]+=a[i]-b[i];
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}