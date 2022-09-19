#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        if(n%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int l,r;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(') l=i;
            else if(s[i]==')') r=i;
        }
        if(l<=r || (r!=0 && l!=(s.size()-1))) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}