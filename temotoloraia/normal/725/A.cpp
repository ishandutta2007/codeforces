#include <bits/stdc++.h>
using namespace std;
int n,ans[200005],pas;
string s;
int main ()
{
    cin>>n>>s;
    for (int i=0;i<s.size() && s[i]=='<';i++)ans[i]=1;
    for (int i=s.size()-1;i>=0 && s[i]=='>';i--)ans[i]=1;
    for (int i=0;i<s.size();i++)pas+=ans[i];
    cout<<pas<<endl;
}