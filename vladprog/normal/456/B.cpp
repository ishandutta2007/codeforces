#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    s="0"+s;
    int n=((int)s[s.length()-2]-48)*10+(int)s[s.length()-1]-48;
    cout<</*s<<'\n'<<n<<'\n'<<*/((n%4)?0:4);
}