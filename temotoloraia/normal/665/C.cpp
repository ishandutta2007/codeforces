#include <bits/stdc++.h>
using namespace std;
string s;
int i;
main()
{
    cin>>s;
    cout<<s[0];
    for (i=1;i<s.size();i++)
    if (s[i-1]==s[i])
    {
        if (s[i-1]!='a' && s[i+1]!='a')
        {
        cout<<'a';
        s[i]='a';
        }
        else if (s[i-1]!='b' && s[i+1]!='b')
        {
        cout<<'b';
        s[i]='b';
        }
        else //if (s[i-1]!='c' && s[i+1]!='c')
        {
        cout<<'c';
        s[i]='c';
        }
    }
    else
    cout<<s[i];
}