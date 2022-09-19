#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[20];
vector <int> res;
int used[500000];
void togo(int prev,int x)
{
    int u=0;
    for(int j=0;j<18;++j)
    {
        if(((prev>>j)+(x>>j))%2==1)
        {
            u+=po[j];
        }
    }
    res.push_back(u);
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int x;
    cin>>n;
    cin>>x;
    int r=1;
    for(int i=0;i<20;++i)
    {
        po[i]=r;
        r*=2;
    }
    int prev=0;
    for(int i=0;i<(po[n]);++i)
    {
        used[i]=false;
    }
    used[x]=true;
    used[0]=true;
    int u;
    for(int i=0;i<po[n];++i)
    {
        if(used[i]==false)
        {
            u=0;
            togo(prev,i);
            for(int j=0;j<n;++j)
            {
                if(((i>>j)%2+(x>>j)%2)==1)
                {
                    u+=po[j];
                }
            }
            if(x<po[n])
            {
            used[u]=true;
            }
            prev=i;
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}