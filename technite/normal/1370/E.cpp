#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int a=0,b=0;
    int s1=0,t1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) continue;
        else if(s[i]=='1')
        {
            s1++;
            a=max(0,a-1);
            b++;
        }
        else
        {
            t1++;
            b=max(0,b-1);
            a++;
        }
    }
    if(s1!=t1) cout<<-1<<'\n';
    else cout<<a+b<<'\n';
}