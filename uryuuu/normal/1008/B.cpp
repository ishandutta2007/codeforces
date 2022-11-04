#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,t=0,xiao,da,sz;
    int n;
    cin>>n;
        cin>>a>>b;
    sz=max(a,b);
    for(int i=1;i<n;i++)
    {
            cin>>a>>b;
            xiao=min(a,b);
            da=max(a,b);
        if(sz>=da)
            sz=da;
        else if (sz>=xiao)
            sz=xiao;
        else
            t++;
        }
    if(t)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
    }