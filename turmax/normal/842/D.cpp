#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1000000;
int u[maxn][20];
bool change[20];
int go(int x,int y)
{
    if(u[x][y]==(1<<y))
    {
        return (1<<y);
    }
    else if(y==0)
    {
        return 0;
    }
    if(change[y-1])
    {
        int z=go(2*x+1,y-1);
        if(z==(1<<(y-1)))
        {
            return z+go(2*x,y-1);
        }
        else
        {
            return z;
        }
    }
    else
    {
        int z=go(2*x,y-1);
        if(z==(1<<(y-1)))
        {
            return z+go(2*x+1,y-1);
        }
        else
        {
            return z;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    set <int> u1;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        int y=x;
        if(!u1.count(x))
        {
            int z=0;
            while(z<20)
            {
                u[x][z]++;
                x/=2;
                z++;
            }
        }
        u1.insert(y);
    }
    //cout<<go(0,19)<<" ans "<<endl;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        for(int i=0;i<20;++i)
        {
            if((x & (1<<i)))
            {
                change[i]=(!change[i]);
            }
        }
        cout<<go(0,19)<<endl;
    }
    return 0;
}