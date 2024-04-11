#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin>>n;
    int sum=0;
    int prev,x;
    int prev1=0;
    cin>>prev;
    for(int i=1;i<n;++i)
    {
        cin>>x;
        if(x==1)
        {
            if(prev==2)
            {
                sum+=3;
            }
            else if(prev==3)
            {
                sum+=4;
            }
        }
        else if(x==2)
        {
            if(prev==1)
            {
                sum+=3;
            }
            else if(prev==3)
            {
                cout<<"Infinite";
                return 0;
            }
        }
        else if(x==3)
        {
            if(prev==1)
            {
                sum+=4;
            }
            else if(prev==2)
            {
                cout<<"Infinite";
                return 0;
            }
        }
        if(prev1==3 && prev==1 && x==2)
        {
            sum--;
        }
        prev1=prev;
        prev=x;
    }
    cout<<"Finite"<<endl;
    cout<<sum;
    return 0;
}