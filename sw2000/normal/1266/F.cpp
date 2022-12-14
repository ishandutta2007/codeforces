#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=5e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

vector<pii>v[maxn];
vector<int>to[maxn];
map<int,int>m[maxn];
pii e[maxn];
int n,ma1[maxn],ma2[maxn],pre[maxn],ans[maxn];

void init(int x,int f)
{
    for(auto &i:v[x])if(i.y!=f)
    {
        init(i.y,x);
        i.x=ma1[i.y]+1;
        ma2[x]=max(ma2[x],i.x);
        if(i.x>=ma1[x])
        {
            ma2[x]=ma1[x];
            ma1[x]=i.x;
        }
    }
}
void init1(int x,int f)
{
    for(auto &i:v[x])
    {
        if(i.y==f)
        {
            if(ma1[x]==ma1[f]-1)
            {
                i.x=ma2[f]+1;
            }
            else
            {
                i.x=ma1[f]+1;
            }
            ma2[x]=max(ma2[x],i.x);
            if(i.x>=ma1[x])
            {
                ma2[x]=ma1[x];
                ma1[x]=i.x;
            }
            break;
        }
    }
    for(auto i:v[x])if(i.y!=f)
    {
        init1(i.y,x);
    }
}

void s1()
{
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end(),greater<pii>());
        for(int j=1;j<v[i].size();j++)
        {
            pre[j+1]=max(pre[j+1],v[i][j].x*2);
            if(v[i][j].x!=v[i][j-1].x)
                pre[j+1]=max(pre[j+1],v[i][j].x*2+1);
        }
    }
}

void s2(int o)
{
    int a=e[o].x,b=e[o].y;
    vector<pii>tmp;
    for(int i=0,j=0;i<to[a].size()-1||j<to[b].size()-1;)
    {
        int x,y;
        if(i==to[a].size()-1)x=-1;
        else x=v[a][to[a][i]].x;
        if(j==to[b].size()-1)y=-1;
        else y=v[b][to[b][j]].x;
        if(x==y)
        {
            i++;j++;
            tmp.push_back({x,to[a][i]+to[b][j]});
        }
        else if(x>y)
        {
            i++;
            tmp.push_back({x,to[a][i]+to[b][j]});
        }
        else
        {
            j++;
            tmp.push_back({y,to[a][i]+to[b][j]});
        }
    }
    int p=m[a][b],q=m[b][a];
    for(auto &i:tmp)
    {
        if(i.x<=p)i.y--;
        if(i.x<=q)i.y--;
        pre[i.y]=max(pre[i.y],i.x*2);
    }

}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&e[i].x,&e[i].y);
        v[e[i].x].push_back({-1,e[i].y});
        v[e[i].y].push_back({-1,e[i].x});
    }
    init(1,0);
    init1(1,0);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<ma1[i]<<' '<<ma2[i]<<endl;
//        for(auto j:v[i])cout<<j.x<<' '<<j.y<<endl;
//        cout<<"------------------------"<<endl;
//    }
    pre[1]=n;
    for(int i=1;i<=n;i++)
        ans[1]=max(ans[1],(int)v[i].size()+1);
    s1();
    for(int i=n,j=2;i;i--)
    {
        while(j<=pre[i])
        {
            ans[j]=i;
            j++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto j:v[i])
        {
            m[i][j.y]=j.x;
        }
        to[i].push_back(0);
        for(int j=1;j<v[i].size();j++)
        {
            if(v[i][j].x!=v[i][j-1].x)
                to[i].push_back(j);
        }
        to[i].push_back(v[i].size());
    }
//    for(auto i:v[2])cout<<i.x<<' '<<i.y<<endl;
//    for(auto i:to[2])cout<<i<<' ';
//    cout<<endl;
    for(int i=0;i<n-1;i++)s2(i);



    for(int i=n,j=2;i;i--)
    {
        while(j<=pre[i])
        {
            ans[j]=i;
            j+=2;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}