#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1010;

int arr[maxn<<1];
void solve()
{
    int n;scanf("%d",&n);
    vi v,u;
    for(int i=1;i<=n*2;i++)
    {
        scanf("%d",arr+i);
        arr[i]%=2;
        if(arr[i])v.push_back(i);
        else u.push_back(i);
    }
    if(v.size()%2)
    {
        for(int i=1;i<v.size();i+=2)
        {
            printf("%d %d\n",v[i],v[i+1]);
        }
        for(int i=1;i<u.size();i+=2)
        {
            printf("%d %d\n",u[i],u[i+1]);
        }
    }
    else
    {
        if(v.empty())swap(v,u);
        for(int i=2;i<v.size();i+=2)
        {
            printf("%d %d\n",v[i],v[i+1]);
        }
        for(int i=0;i<u.size();i+=2)
        {
            printf("%d %d\n",u[i],u[i+1]);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}