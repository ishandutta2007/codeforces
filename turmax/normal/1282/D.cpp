#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int sz;
    string s1;
    string s2;
    int x1,x2;
    int x;
    for(int i=0;i<300;++i)
    {
        s1+='a';
        s2+='b';
    }
    cout<<s1<<endl;
    cin>>x1;
    if(x1==0)
    {
        exit(0);
    }
    cout<<s2<<endl;
    cin>>x2;
    if(x2==0)
    {
        exit(0);
    }
    sz=((300-x1)+(300-x2));
    int a[sz+1];
    a[0]=(x1-(300-sz));
    a[sz]=(x2-(300-sz));
    for(int i=1;i<sz;++i)
    {
        string s;
        for(int j=0;j<i;++j)
        {
            s+='b';
        }
        for(int j=i;j<sz;++j)
        {
            s+='a';
        }
        cout<<s<<endl;
        cin>>x;
        if(x==0)
        {
            exit(0);
        }
        a[i]=x;
    }
    string res;
    for(int i=1;i<=sz;++i)
    {
        if(a[i]>a[i-1])
        {
            res+='a';
        }
        else
        {
            res+='b';
        }
    }
    cout<<res<<endl;
    cin>>x;
    exit(0);
    return 0;
}