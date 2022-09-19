#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int pr1=1,pr2=1;
    cin>>s;
    int n=s.size();
    int x;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        if((s[i]=='u'  || s[i]=='n') && (i!=0 && s[i]==s[i-1]))
        {
            x=pr1+pr2;
        }
        else
        {
            x=pr1;
        }
        pr2=pr1;
        pr1=(x%p);
    }
    cout<<pr1;
    return 0;
}