#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    bool used1[n];
    bool used2[n];
    vector <int> v1;
    vector <int> v2;
    for(int i=0;i<n;++i)
    {
        used1[i]=false;
        used2[i]=false;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
        if(a[i]!=(-1))
        {
            used1[i]=true;
            used2[a[i]]=true;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(!used1[i])
        {
            v1.push_back(i);
        }
        if(!used2[i])
        {
            v2.push_back(i);
        }
    }
    if(v1.size()==1)
    {
        a[v1[0]]=v2[0];
        for(int i=0;i<n;++i)
        {
            cout<<a[i]+1<<" ";
        }
        return 0;
    }
    for(int i=0;i<v1.size();++i)
    {
        //cout<<i<<endl;
        //cout<<v1.size()-3<<endl;
        if(i<=(((int) v1.size())-3))
        {
            if(v1[i]!=v2[v2.size()-1])
            {
                a[v1[i]]=v2[v2.size()-1];
                v2.erase(v2.begin()+v2.size()-1);
            }
            else if(v1[i]!=v2[v2.size()-2])
            {
                a[v1[i]]=v2[v2.size()-2];
                v2.erase(v2.begin()+v2.size()-2);
            }
        }
        else
        {
            //cout<<" tgfds "<<endl;
            if(v1[i]!=v2[v2.size()-1] && v1[i+1]!=v2[v2.size()-2])
            {
                a[v1[i]]=v2[v2.size()-1];
                a[v1[i+1]]=v2[v2.size()-2];
            }
            else if(v1[i]!=v2[v2.size()-2] && v1[i+1]!=v2[v2.size()-1])
            {
                a[v1[i]]=v2[v2.size()-2];
                a[v1[i+1]]=v2[v2.size()-1];
            }
            break;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]+1<<" ";
    }
    return 0;
}