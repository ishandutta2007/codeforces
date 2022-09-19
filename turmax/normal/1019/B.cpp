#include <bits/stdc++.h>

using namespace std;
#define int long long
int query(int pos)
{
    cout<<"? "<<(pos+1)<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int razn(int pos,int n)
{
    return query(pos)-query((pos+n/2)%n);
}
void getans(int x)
{
    cout<<"! "<<(x+1)<<endl;
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n%4==2)
    {
        cout<<"! "<<(-1)<<endl;
        return 0;
    }
    else
    {
        int u=razn(0,n);
        int low=0;
        int up=(n/2);
        int zlow=u;
        int zup=(-u);
        if(u==0)
        {
            getans(0);
        }
        while(true)
        {
            int m=(low+up)/2;
            int z=razn(m,n);
            if(z==0)
            {
                getans(m);
            }
            if(z*zup<=0)
            {
                zlow=z;
                low=m;
            }
            else
            {
                zup=z;
                up=m;
            }
        }
    }
    return 0;
}