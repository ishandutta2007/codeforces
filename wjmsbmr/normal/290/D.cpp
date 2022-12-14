#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s;int t;
int main()
{
    cin>>s>>t;
    for(int i=0;i<(int)s.length();i++)
    {
        if('A'<=s[i]&&s[i]<='Z')s[i]=s[i]-'A'+'a';
        if(s[i]<t+97)s[i]=s[i]-'a'+'A';
    }
    cout<<s<<endl;
    return 0;
}