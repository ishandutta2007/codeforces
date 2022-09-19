#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=30;
int parent[maxn];
int glav(int x)
{
    int y=x;
    while(true)
    {
        if(parent[y]==(-1))
        {
            return y;
        }
        y=parent[y];
    }
}
void merg(int x,int y)
{
    x=glav(x);y=glav(y);
    if(x!=y) parent[x]=y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    for(int i=0;i<maxn;++i) parent[i]=(-1);
    int n;
    string s1,s2;
    cin>>n;
    cin>>s1>>s2;
    bool h=true;
    for(int i=0;i<n;++i)
    {
        if(s1[i]>s2[i])
        {
            cout<<(-1)<<endl;
            h=false;
            break;
        }
    }
    if(!h) continue;
    vector <int> a[25];
    for(int i=0;i<n;++i)
    {
        merg(s1[i]-'a',s2[i]-'a');
    }
    set <int> d;
    for(int i=0;i<maxn;++i)
    {
        d.insert(glav(i));
    }
    int o=d.size();
    cout<<(maxn-o)<<endl;
    }
    return 0;
}