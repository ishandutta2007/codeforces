#include<bits/stdc++.h>
using namespace std;
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
int main()
{
    TT
    {
        string s;
        cin>>s;
        int n;
        n=s.length();
        vector<int> z(n+1,0),o(n+1,0);
        for(int i=0;i<n;i++){
            z[i+1]=z[i]+(s[i]=='0');
            o[i+1]=o[i]+(s[i]=='1');
        }
        int cost=1e5+1;
        for(int i=0;i<n;i++)
        {
            cost=min(cost,i-z[i]+n-i-(o[n]-o[i]));
            cost=min(cost,i-o[i]+n-i-(z[n]-z[i]));
        }
 
        cout<<cost<<'\n';
    }
}