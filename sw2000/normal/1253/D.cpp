#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int father[maxn],n,m;
vector<int>v;

int fd(int a)
{
    if(a==father[a])return a;
    return father[a]=fd(father[a]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i]=i;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int fa=fd(a),fb=fd(b);

        if(fa!=fb)
        {
            if(fa<fb)swap(fa,fb);
            father[fb]=fa;
        }
    }

    int ans=0;
    for(int a=1;a<=n;)
    {
        int fa=fd(a);
        for(int b=a+1;b<=fa;b++)
        {
            int fb=fd(b);
            if(fa!=fb)
            {
                if(fa<fb)swap(fa,fb);
                father[fb]=fa;
                ans++;
            }
        }
        a=fa+1;
    }
    printf("%d",ans);
    return 0;
}