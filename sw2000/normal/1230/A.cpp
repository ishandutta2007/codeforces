#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e5;
const int maxn=2e5+10;

int main()
{
    int a[4],sum=0;
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum&1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<4;i++)
    {
        if(a[i]+a[0]==sum/2)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<4;i++)
    {
        if(a[i]==sum/2)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}