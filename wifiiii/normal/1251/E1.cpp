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

// 1 2 3 4 5 6
// 3 3 4 4|5 5
// 2 2|3 3
//|1 1

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;++i) cin>>a[i]>>b[i];
        vector<int> ord(n);
        iota(al(ord),0);
        sort(al(ord),[&](int i,int j) {return a[i]>a[j];});
        ll ans=0;
        priority_queue<int,vector<int>,greater<int>> q;
        int cur=n;
        for(int i:ord) {
            q.push(b[i]);
            if(a[i]>=cur) {
                ans+=q.top();
                q.pop();
                ++cur;
            }
            --cur;
        }
        cout<<ans<<endl;
    }
}