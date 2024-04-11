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
typedef pair<int,int> pii;

const int maxn = 100005;
int prime[maxn],np[maxn],tot=0;
void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           if(i%prime[j]==0) break;
       }
   }
}
int main() {
    init(maxn-1);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        // x is not prime, but x + n - 1 is a prime
        int ans=0;
        for(int x=1;;++x) {
            if(np[x] && !np[x+n-1]) {
                ans = x;
                break;
            }
        }
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                if(i == j) {
                    cout << ans << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
    }
}