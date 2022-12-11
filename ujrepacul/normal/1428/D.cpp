#include <bits/stdc++.h>
using namespace std;
int v[100005];
vector<int>v1,v2,v3;
int nxt[100005];
int ok[100005];
struct ura
{
    int x,y;
};
vector<ura>rz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=n;i>=1;--i)
    {
        if(v[i]==1)
            v1.push_back(i);
        else if(v[i]==2)
        {
            if((int)v1.size()==0)
            {
                cout<<-1;
                return 0;
            }
            nxt[i]=v1[(int)v1.size()-1];
            v1.pop_back();
            v2.push_back(i);
        }
        else if(v[i]==3)
        {
            if(v3.size())
            {
                nxt[i]=v3[(int)v3.size()-1];
                v3.pop_back();
            }
            else if(v2.size())
            {
                nxt[i]=v2[(int)v2.size()-1];
                v2.pop_back();
            }
            else if(v1.size())
            {
                nxt[i]=v1[(int)v1.size()-1];
                v1.pop_back();
            }
            else
            {
                cout<<-1;
                return 0;
            }
            v3.push_back(i);
        }
    }
    k=1;
    for(i=1;i<=n;++i)
    {
        if(v[i]==3)
        {
            rz.push_back({k,i});
            rz.push_back({k++,nxt[i]});
        }
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]==2)
        {
            rz.push_back({k,i});
            rz.push_back({k++,nxt[i]});
            ok[nxt[i]]=1;
        }
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]==1 && !ok[i])
            rz.push_back({k++,i});
    }
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
        cout<<rz[i].x<<' '<<rz[i].y<<'\n';
    return 0;
}