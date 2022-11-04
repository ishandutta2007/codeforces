#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
const ll Mod=1000000007;

vector<ll>v;
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        ll cnt=1;
        while(s[i]==s[i+1])
        {
            cnt++;
            i++;
        }
        v.push_back(cnt);
    }
    ll ans=n*(n-1)/2;
    ll sum=0;
    for(int i=0;i<v.size();i++)
    {
        if(i!=0)
            sum+=v[i-1]-1;
        if(i!=v.size()-1)
            sum+=v[i+1];
    }
    ll res=ans-sum;
    cout<<res<<endl;
    return 0;
}