#include <bits/stdc++.h>

using namespace std;

long long int typedef li;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n=(int)s.size();
        if(s[n-2]=='p' && s[n-1]=='o') cout<<"FILIPINO\n";
        else if(s.substr(n-4)=="desu") cout<<"JAPANESE\n";
        else if(s.substr(n-4)=="masu") cout<<"JAPANESE\n";
        else cout<<"KOREAN\n";
    }
    return 0;
}