#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <pair<int,int> > a;
    string s;
    for(int i=0;i<3;++i)
    {
        cin>>s;
        a.push_back({s[0]-'0',s[1]-'a'});
    }
    int l=1;
    bool p;
    for(int i=0;i<3;++i)
    {
        p=false;
        for(int j=0;j<i;++j)
        {
            if(a[i]==a[j])
            {
                if(l==1)
                {
                    ++l;
                }
                p=true;
                break;
            }
        }
        if(p==true)
        {
            break;
        }
    }
    for(int i=0;i<3;++i)
    {
        p=false;
        for(int j=0;j<i;++j)
        {
            if(a[i].second==a[j].second && abs(a[i].first-a[j].first)<=2)
            {
                if(l==1)
                {
                    ++l;
                }
                p=true;
                break;
            }
        }
        if(p==true)
        {
            break;
        }
    }
    if(a[0]==a[1] && a[1]==a[2])
    {
        l=3;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if((a[0].second==a[1].second && (a[0].first-a[1].first)==1) && (a[1].second==a[2].second && (a[1].first-a[2].first)==1))
    {
        l=3;
    }
    cout<<(3-l);
    return 0;
}