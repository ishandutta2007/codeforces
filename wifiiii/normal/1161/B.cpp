
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))


vector<pair<int,int>> v,v2;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        v.pb({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;++i)
    {
        if(n%i) continue;
        v2.clear();
        for(auto p:v)
        {
            int a=(p.first+i-1)%n+1,b=(p.second+i-1)%n+1;
            if(a>b) swap(a,b);
            v2.pb({a,b});
        }
        sort(v2.begin(),v2.end());
        if(v==v2) {cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}