#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100005;
int po[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        po[i]=u;
        if(u<1e15)
        {
            u*=2;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    string s;
    for(int i=0;i<n;++i)
    {
        s+='a';
    }
    for(int x=1;x<n;++x)
    {
        if(((x*(x-1))/2)<k && (x*(x+1)/2)>=k)
        {
            s[x]='b';
            s[k-x*(x-1)/2-1]='b';
            break;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    }
    return 0;
}