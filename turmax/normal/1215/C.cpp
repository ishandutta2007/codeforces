#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    vector <int> v1;
    vector <int> v2;
    for(int i=0;i<n;++i)
    {
        if(s1[i]=='a' && s2[i]=='b')
        {
            v1.push_back(i);
        }
        else if(s1[i]=='b' && s2[i]=='a')
        {
            v2.push_back(i);
        }
    }
    vector <pair<int,int> > res;
    int x1,x2;
    while(v1.size()>=2)
    {
        x1=v1[v1.size()-1];
        x2=v1[v1.size()-2];
        v1.erase(v1.begin()+v1.size()-1);
        v1.erase(v1.begin()+v1.size()-1);
        res.push_back({x1,x2});
    }
    while(v2.size()>=2)
    {
        x1=v2[v2.size()-1];
        x2=v2[v2.size()-2];
        v2.erase(v2.begin()+v2.size()-1);
        v2.erase(v2.begin()+v2.size()-1);
        res.push_back({x1,x2});
    }
    if(v1.size()==1 && v2.size()==1)
    {
        res.push_back({v1[0],v1[0]});
        res.push_back({v1[0],v2[0]});
    }
    if((v1.size()+v2.size())==1)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();++i)
        {
            cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
        }
    }
    return 0;
}