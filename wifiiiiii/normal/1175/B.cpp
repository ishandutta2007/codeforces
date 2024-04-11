
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

const ll ov = (1ll<<32)-1;
int fs[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll now = 1;
    ll ans = 0;
    int f1 = 0, f2 = 0;
    vector<ll> vec;
    while(n--)
    {
        string s;
        cin>>s;
        if(s=="add")
        {
            if(fs[vec.size()])
            {
                f2 = 1;
                break;
            }
            ans += now;
            if(ans > ov)
            {
                f2 = 1;
                break;
            }
        }
        else if(s=="for")
        {
            int t;
            cin>>t;
            vec.push_back(t);
            if(fs[vec.size()-1] || now * t > ov) fs[vec.size()] = 1;
            else now *= t, fs[vec.size()] = 0;
        }
        else
        {
            if(fs[vec.size()] == 0) now /= vec.back();
            vec.pop_back();
        }
    }
    if(f2) cout<<"OVERFLOW!!!"<<endl;
    else cout<<ans<<endl;
}