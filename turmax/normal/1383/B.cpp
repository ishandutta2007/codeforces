#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    int c[30];
    for(int i=0;i<30;++i) c[i]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=0;j<30;++j)
        {
            if(a[i] & (1<<j))
            {
                c[j]++;
            }
        }
    }
    bool o=false;
    for(int j=29;j>=0;j--)
    {
        if(c[j]%2==1)
        {
            int k=c[j];
            bool h=(k%4==1);
            bool u=((n-k)%2==0);
            if(h || !u)
            {
                cout<<"WIN"<<endl;
                o=true;
                break;
            }
            else
            {
                cout<<"LOSE"<<endl;
                o=true;
                break;
            }
        }
    }
    if(!o)
    {
        cout<<"DRAW"<<endl;
    }
    }
    return 0;
}