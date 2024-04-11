#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int n,arr[maxn],cnt=1,l[maxn],r[maxn];
vector<int>v[maxn];

void init(int o,int f)
{
    int id=-1;
    for(int i=0;i<v[o].size();i++)
    {
        if(v[o][i]==f)id=i;
        else init(v[o][i],o);
    }
    if(~id)v[o].erase(v[o].begin()+id);
}

void dfs(int x)
{
    for(int i=v[x].size()-1;i>=0;i--)
    {
        arr[++cnt]=v[x][i];
    }
    arr[++cnt]=x;
    for(auto i:v[x])dfs(i);
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    init(1,0);
//    for(int i=1;i<=n;i++)
//    {
//        for(auto j:v[i])
//            cout<<j<<' ';
//        cout<<endl;
//    }
    arr[1]=1;
    dfs(1);
    for(int i=1;i<=2*n;i++)
    {
        if(!l[arr[i]])l[arr[i]]=i;
        else r[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",l[i],r[i]);
    }
    return 0;
}