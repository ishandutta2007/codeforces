#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int t1=0;
    int t2=0;
    bool a[n][2];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<2;++j)
        {
            a[i][j]=false;
        }
    }
    int x,y;
    bool h=true;
    for(int i=0;i<q;++i)
    {
        cin>>x>>y;
        swap(x,y);
        x--;y--;
        if(a[x][y])
        {
            if(y==1 && x==(n-1))
            {
                h=true;
            }
            if(x!=0 && a[x-1][1-y])
            {
                t2--;
            }
            if(x!=(n-1) && a[x+1][1-y])
            {
                t2--;
            }
            if(a[x][1-y])
            {
                t1--;
            }
            a[x][y]=false;
        }
        else
        {
            //cout<<x<<" "<<y<<" gfred "<<endl;
            if(y==1 && x==(n-1))
            {
                h=false;
            }
            if(x!=0 && a[x-1][1-y])
            {
                t2++;
            }
            if(x!=(n-1) && a[x+1][1-y])
            {
                t2++;
            }
            if(a[x][1-y])
            {
                t1++;
            }
            a[x][y]=true;
        }
        //cout<<t1<<" "<<t2<<endl;
        if(t1==0 && t2==0 && h)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}