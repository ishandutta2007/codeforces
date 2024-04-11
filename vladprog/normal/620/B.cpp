#include<bits/stdc++.h>

using namespace std;

const int c[10]={6,2,5,5,4,5,6,3,7,6};

int f(int k)
{
    string s=to_string(k);
    int res=0;
    for(int i=0;i<s.length();i++)
        res+=c[(int)s[i]-48];
    return res;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++)
        ans+=f(i);
    cout<<ans;
}