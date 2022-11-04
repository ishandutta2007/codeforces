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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
const int maxn=5e5+10;
int a[maxn],f[maxn],s[maxn];
int n,m;
int findx(int x)
{
    if(f[x]==x)
        return x;
    return f[x]=findx(f[x]);
}
void jihe(int a,int b)
{
    int fa=findx(a);
    int fb=findx(b);
    if(fa!=fb)
        f[fa]=fb;
}
int main()
{
    mm(s);
    int aa;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    while(m--)
    {
        cin>>aa;
        for(int i=0;i<aa;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<aa;i++)
        {
            jihe(a[i-1],a[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        s[findx(i)]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<s[f[i]]<<' ';
    }
    cout<<endl;
    return 0;
}