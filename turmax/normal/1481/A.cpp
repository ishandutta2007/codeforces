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
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int x1=0,x2=0,y1=0,y2=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='U')
            {
                y1++;
            }
            else if(s[i]=='D') {y2--;}
            else if(s[i]=='R') {x1++;}
            else {x2--;}
        }
        if(x<=x1 && x>=x2 && y<=y1 && y>=y2) {cout<<"YES"<<endl;}
        else cout<<"NO"<<endl;
    }
    return 0;
}