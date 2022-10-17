#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n==1) {
            cout<<"9\n";
        } else if(n==2) {
            cout<<"98\n";
        } else {
            string s(n,'0');
            s[0]='9',s[1]='8';
            for(int i=2;i<n;++i) {
                s[i]=(i+7)%10+'0';
            }
            cout<<s<<endl;
        }
    }
}