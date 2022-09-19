#include <bits/stdc++.h>

using namespace std;
#define int long long
map <pair<pair<int,int>,pair<int,int> >,int> u;
int f(int a,int b,int c,int d)
{
    if(a>b || c>d)
    {
        return 0;
    }
    if(a==0 && b==0)
    {
        return d-c+1;
    }
    if(c==0 && d==0)
    {
        return b-a+1;
    }
    if(u.count({{a,b},{c,d}})==1)
        {
            return u[{{a,b},{c,d}}];
        }
    int sum=0;
    sum+=f(a/2,(b-1)/2,(c+1)/2,d/2);
    sum+=f((a+1)/2,b/2,c/2,(d-1)/2);
    sum+=f((a+1)/2,b/2,(c+1)/2,d/2);
    u[{{a,b},{c,d}}]=sum;
    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int l,r;
        cin>>l>>r;
        cout<<f(l,r,l,r)<<endl;
    }
    return 0;
}