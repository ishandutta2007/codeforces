#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll sz[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll l,r;
        cin>>n>>l>>r;
        sz[0] = 1;
        sz[1] = 2*(n-2);
        for(int i=2;i<n;++i) sz[i] = 2*(n-i-1)+2;
        sz[n] = sz[n+1] = 1;
        auto get = [&](int x) -> vector<int> {
            if(x == 0 || x == n+1) return vector<int> {1};
            if(x == n) return vector<int> {n};
            if(x == 1)
            {
                vector<int> ret(sz[1]);
                int tp=1;
                for(int i=0;i<ret.size();i+=2) ret[i]=++tp,ret[i+1]=1;
                return ret;
            }
            vector<int> ret;
            ret.push_back(n);
            int tp = x + 1;
            while(tp < n)
            {
                ret.push_back(x);
                ret.push_back(tp++);
            }
            ret.push_back(x);
            return ret;
        };
//        for(int i=0;i<=n+1;++i) cout<<sz[i]<<" ";cout<<endl;
//        for(int i=0;i<=n+1;++i) {
//            vector<int> v = get(i);
//            cout << i << ": " << endl;
//            for(int i : v) cout << i << " ";
//            cout << endl;
//        }
        ll cur = 1;
        vector<int> ans;
        for(int i=0;i<=n+1;++i)
        {
            ll L=cur, R=cur+sz[i]-1;
            if(min(R,r) >= max(L,l))
            {
                vector<int> v = get(i);
                for(ll i=max(L,l);i<=min(r,R);++i) ans.push_back(v[i-L]);
            }
            cur = R+1;
        }
        for(int i:ans) cout<<i<<" ";cout<<endl;
    }
}