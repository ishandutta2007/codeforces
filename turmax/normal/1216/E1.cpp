#include <bits/stdc++.h>

using namespace std;
#define int long long
string sti(int x)
{
    string ans;
    if(x==0)
    {
        return "0";
    }
    while(x!=0)
    {
        ans.push_back(x%10+'0');
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<pair<int,string> > s;
    string u;
    int curr=0;
    int sum=0;
    for(int i=1;i<40000;++i)
    {
        string h=sti(i);
        u+=h;
        sum+=h.size();
        curr+=(sum);
        s.push_back({curr,h});
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            cout<<'1'<<endl;
            continue;
        }
        pair <int,string> z=(s[lower_bound(s.begin(),s.end(),(pair<int,string> {x,"0"}))-s.begin()-1]);
        int h=x-z.first;
        cout<<u[h-1]<<endl;
    }
    return 0;
}