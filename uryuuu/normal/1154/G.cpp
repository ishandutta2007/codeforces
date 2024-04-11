#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
#define N 500005
#define mod 1000000007
ll inf=1e18;
using namespace std;
const ll maxn=1e7+5;
int n,num,p1,p2,per1,per2,siz;
ll ans,now0,now1,now2,a;
bool vis[maxn];
vector<int>vec[maxn];
int main()
{
    while(cin>>n)
    {
        ans=inf;
        per1=per2=0;
        for(ll i=0LL;i<maxn;i++)
        {
            vec[i].clear();
        }
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            vec[a].push_back(i);
            vis[a]=true;
        }
        for(ll i=1ll;i<maxn;i++)
        {
            num=0;
            for(ll j=i;j<maxn&&num<2;j+=i)
            {
                if(!vis[j])
                    continue;
                if(num==0)
                {
                    siz=vec[j].size();
                    if(siz==1)
                    {
                        num++;
                        p1=vec[j][0];
                        now1=j;
                    }
                    else
                    {
                        num+=2;
                        p1=vec[j][0];
                        p2=vec[j][1];
                        now1=j;
                        now2=j;
                    }
                }
                else
                {
                    num++;
                    now2=j;
                    p2=vec[j][0];
                }
            }
            if(num==2)
            {
                now0=now1/i*now2;
                if(ans>now0)
                {
                    ans=now0;
                    per1=p1;
                    per2=p2;
                }
            }
        }
        cout<<min(per1,per2)<<' '<<max(per1,per2)<<endl;
    }
    return 0;
}