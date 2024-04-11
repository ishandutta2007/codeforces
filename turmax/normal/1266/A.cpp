#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    int sum;
    bool h;
    bool h1;
    for(int i=0;i<n;++i)
    {
    cin>>s;
    h=false;
    sum=0;
    h1=false;
    vector <int> a(s.size());
    for(int i=0;i<s.size();++i)
    {
        a[i]=s[i]-'0';
        sum+=a[i];
        if(a[i]==0 && !h)
        {
            h=true;
        }
        else if(a[i]==0 && h)
        {
            h1=true;
        }
        else if(a[i]%2==0)
        {
            h1=true;
        }
    }
    if(sum%3==0 && h && h1)
    {
        cout<<"red"<<endl;
        continue;
    }
    else
    {
        cout<<"cyan"<<endl;
        continue;
    }
    }
    return 0;
}