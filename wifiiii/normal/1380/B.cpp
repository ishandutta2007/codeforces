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
//#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    int t;
    cin>>t;
    while(t--) {
        int r=0,s=0,p=0;
        string str;
        cin>>str;
        for(char c:str) {
            if(c=='R') r++;
            else if(c=='S') s++;
            else p++;
        }
        if(r>=s && r>=p) cout<<string(str.size(), 'P');
        else if(s>=r && s>=p) cout<<string(str.size(), 'R');
        else if(p>=s && p>=r) cout<<string(str.size(), 'S');
        cout<<endl;
    }
}