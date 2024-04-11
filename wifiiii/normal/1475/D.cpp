#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n),b(n);
        ll tot=0;
        for(int i=0;i<n;++i) cin>>a[i],tot+=a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        if(tot<m) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> a1,a2;
        for(int i=0;i<n;++i) {
            if(b[i]==1) a1.push_back(a[i]);
            else a2.push_back(a[i]);
        }
        sort(a1.begin(),a1.end(),greater<int>());
        sort(a2.begin(),a2.end(),greater<int>());
        vector<ll> sum1(a1.size()+1),sum2(a2.size()+1);
        for(int i=0;i<a1.size();++i) sum1[i+1]=sum1[i]+a1[i];
        for(int i=0;i<a2.size();++i) sum2[i+1]=sum2[i]+a2[i];
        int ans=1e9;
        for(int i=0;i<sum1.size();++i) {
            if(sum2.back()<m-sum1[i]) continue;
            int p=lower_bound(al(sum2),m-sum1[i])-sum2.begin();
            ans=min(ans,i*1+2*p);
        }
        cout<<ans<<endl;
    }
}