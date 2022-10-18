#include<bits/stdc++.h>
using namespace std;
int t[200005];
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int tx=x,ty=y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]==1)
        {
            if(x>0)
            {
                if(y==ty)
                {
                    y--;
                }
                else
                {
                    x--;
                    if(y<ty)
                    {
                        y++;
                    }
                }
            }
            else
            {
                if(y==0)
                {
                    break;
                }
                y--;
            }
        }
        else
        {
            if(y>0)
            {
                y--;
            }
            else
            {
                if(x==0)
                {
                    break;
                }
                x--;
            }
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}