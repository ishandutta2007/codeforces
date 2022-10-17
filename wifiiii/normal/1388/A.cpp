
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[] = {6,10,14,15,21,33,35};
int main() {
    int t;
    cin>>t;
    int m=7;
    while(t--){
        int n;
        cin>>n;
        int ok=0;
        for(int i=0;i<m;++i) {
            if(ok) break;
            for(int j=i+1;j<m;++j) {
                if(ok) break;
                for(int k=j+1;k<m;++k) {
                    if(ok) break;
                    int p=n-a[i]-a[j]-a[k];
                    if(p>0 && p!=a[i] && p!=a[j] && p!=a[k]) {
                        ok=1;
                        cout<<"YES"<<endl;
                        cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<p<<endl;
                    }
                }
            }
        }
        if(!ok) cout<<"NO"<<endl;
    }
}