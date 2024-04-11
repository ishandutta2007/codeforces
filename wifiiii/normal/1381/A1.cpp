
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

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
//        string tmp=s;
        int i=0,j=s.size()-1,k=s.size()-1,f=0;
        vi v;
        while(i <= j) {
            if(f & 1) s[i] = ((s[i]-'0')^1)+'0';
            if(s[i] == t[k]) v.pb(1);
            v.pb(k+1);
            --k;++f;++i;
            if(i > j) break;
            if(f & 1) s[j] = ((s[j]-'0')^1)+'0';
            if(s[j] == t[k]) v.pb(1);
            v.pb(k+1);
            --k;++f;--j;
        }
        cout<<v.size()<<" ";
        for(int i:v) cout<<i<<" ";cout<<endl;
//        for(int i:v) {
//            for(int j=0;j<i;++j) {
//                tmp[j]=((tmp[j]-'0')^1)+'0';
//            }
//            reverse(tmp.begin(),tmp.begin()+i);
//        }
//        cout<<tmp<<" "<<t<<endl;
    }
}