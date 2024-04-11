#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

bool vis[maxn][26];
int father[maxn];

int fd(int a)
{
    if(a==father[a])return a;
    return father[a]=fd(father[a]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        father[i]=i;
    for(int i=0;i<n;i++)
    {
        char a[55];
        scanf("%s",a);
        for(int j=0;j<strlen(a);j++)
        {
            vis[i][a[j]-'a']=1;
        }
        //printf("%s\n",a);
    }


    for(int i=0;i<26;i++)
    {
        int st=-1;
        for(int j=0;j<n;j++)if(vis[j][i])
        {
            if(st==-1)
            {
                st=j;
                continue;
            }
            int fa=fd(st),fb=fd(j);
            if(fa!=fb)
            {
                father[fb]=fa;
            }
        }
    }
    int ans=1;
    for(int i=1;i<n;i++)
    {
        int fa=fd(i),fb=fd(i-1);
        //cout<<fa<<' '<<fb<<endl;
        if(fa!=fb)
        {
            ans++;
            father[fb]=father[fa];
        }
    }
    printf("%d",ans);
    return 0;
}