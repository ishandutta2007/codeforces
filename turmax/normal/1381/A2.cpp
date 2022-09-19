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
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int r=n;
    vector <int> res;
    int o;
    while(r>=3)
    {
        if(s1[r-1]==s2[r-1])
        {
            r--;
            continue;
        }
        o=0;
        res.push_back(r);
        if(s1[r-1]!=s2[r-1])
        {
            if(s1[r-2]!=s2[r-2])
            {
                if(s1[r-1]==s1[r-2])
                {
                    res.push_back(2);
                }
                else if(s1[r-1]!=s2[r-3] || s1[r-3]!=s2[r-1] || r==3)
                {
                    if(s1[r-1]==s2[r-3])
                    {
                        res.push_back(1);
                    }
                    res.push_back(3);
                    if(s1[r-3]==s2[r-1])
                    {
                        res.push_back(1);
                    }
                    o=(-1);
                }
                else
                {
                    if(s1[r-1]==s2[r-4])
                    {
                        res.push_back(1);
                    }
                    res.push_back(4);
                    if(s1[r-4]==s2[r-1])
                    {
                        res.push_back(1);
                    }
                    o=(-2);
                }
            }
            else
            {
                res.push_back(1);
            }
        }
        res.push_back(r);
        r-=2;
        r+=o;
    }
    if(r==2)
    {
        if(s1[0]!=s2[1])
        {
            res.push_back(2);
            if(s1[1]==s2[0])
            {
                res.push_back(1);
            }
        }
        else
        {
            res.push_back(1);
            res.push_back(2);
            if(s1[1]==s2[0])
            {
                res.push_back(1);
            }
        }
    }
    else if(r==1)
    {
        if(s1[0]!=s2[0])
        {
            res.push_back(1);
        }
    }
    cout<<res.size()<<' ';
    for(auto v:res) cout<<v<<' ';
    cout<<endl;
    }
    return 0;
}