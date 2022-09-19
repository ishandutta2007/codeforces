#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>k;
    int res[4][4];
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(i==1 && j==2)
            {
                res[i][j]=(1<<17);
            }
            else if(i==2 && j==1)
            {
                res[i][j]=(1<<17);
            }
            else if((i+j)==3)
            {
                res[i][j]=k;
            }
            else if(i==3 && j==3)
            {
                res[i][j]=k;
            }
            else
            {
                res[i][j]=(k+(1<<17));
            }
        }
    }
    cout<<4<<" "<<4<<endl;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}