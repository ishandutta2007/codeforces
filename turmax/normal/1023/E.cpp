#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
bool query(pair <int,int> a,pair <int,int> b)
{
    if(a.first<n && a.second<n && b.first>=0 && b.second>=0)
    {
        cout<<"? "<<a.first+1<<" "<<a.second+1<<" "<<b.first+1<<" "<<b.second+1<<endl;
        string t;
        cin>>t;
        if(t=="YES")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int dist(pair <int,int> a,pair <int,int> b)
{
    return b.first-a.first+b.second-a.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    pair <int,int> curr={0,0};
    pair <int,int> f={n-1,n-1};
    string ans1;
    while(dist(curr,f)>=n)
    {
        curr.first++;
        if(query(curr,f))
        {
            ans1+='D';
            continue;
        }
        curr.first--;
        curr.second++;
        ans1+='R';
    }
    curr={0,0};
    string ans2;
    while(dist(curr,f)>=n)
    {
        f.second--;
        if(query(curr,f))
        {
            ans2+='R';
            continue;
        }
        f.second++;
        f.first--;
        ans2+='D';
    }
    reverse(ans2.begin(),ans2.end());
    cout<<"! "<<ans1+ans2;
    return 0;
}