#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin>>s;
    int ans=(s.size()+1)/2;
    if(ans*2-1==s.size())
    {
        int f=1;
        for(int i=1;i<s.size();++i) if(s[i]=='1') f=0;
        if(f) ans--;
    }
    cout<<ans<<endl;
}