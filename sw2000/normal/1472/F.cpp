#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
typedef pair<int,int>pii;
pii arr[N];

bool solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
    }
    sort(arr+1,arr+1+m,[](pii a,pii b){return a.se<b.se;});
    if(m%2)return 0;
    for(int i=3;i<m;i+=2)
    {
        if(arr[i].se==arr[i-1].se)return 0;
    }
    for(int i=2;i<=m;i+=2)
    {
        if(arr[i].fi==arr[i-1].fi)
        {
            if(arr[i].se%2==arr[i-1].se%2)return 0;
        }
        else
        {
            if(arr[i].se%2!=arr[i-1].se%2)return 0;
        }
    }
    return 1;
}
int main()
{
    int _;
    cin>>_;
    while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}