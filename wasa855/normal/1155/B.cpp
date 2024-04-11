#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    int sum=0;
    for(int i=0;i<n-10;i++)
    {
        if(s[i]=='8') sum++;
    }
    int xx=(n-11)/2;
    if(xx<sum) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}