#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
bool used[maxn];
bool cmp(vector <int> a,vector <int> b)
{
    return a.size()<b.size();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
    }
    vector <vector <int> > v;
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            vector <int> h;
            int curr=i;
            while(true)
            {
                used[curr]=true;
                h.push_back(curr);
                curr=a[curr];
                if(curr==i)
                {
                    break;
                }
            }
            v.push_back(h);
        }
    }
    sort(v.begin(),v.end(),cmp);
    int ans[n];
    bool used1[n];
    for(int i=0;i<n;++i) used1[i]=false;
    for(int i=0;i<v.size();++i)
    {
        //cout<<v[i].size()<<endl;
        if(used1[i])
        {
            continue;
        }
        if(v[i].size()%2==1)
        {
        for(int j=0;j<v[i].size();++j)
        {
            ans[v[i][j]]=v[i][((v[i].size()+1)/2+j)%v[i].size()];
        }
        }
        else
        {
            //cout<<i<<" i "<<endl;
            if(i<(v.size()-1) && v[i].size()==v[i+1].size())
            {
                //cout<<i<<" i "<<endl;
                used1[i]=true;used1[i+1]=true;
                for(int j=0;j<v[i].size();++j)
                {
                    ans[v[i][j]]=v[i+1][j];
                    ans[v[i+1][j]]=v[i][(j+1)%v[i].size()];
                }
            }
            else
            {
                cout<<(-1);
                return 0;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]+1<<' ';
    }
    return 0;
}