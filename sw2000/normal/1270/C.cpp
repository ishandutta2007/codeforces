#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
int n;
ll two[100];
vector<int>a,b;

void solve()
{
    int len=max(a.size(),b.size());
    for(int i=len-a.size()+1;i--;)a.push_back(0);
    for(int i=len-b.size()+1;i--;)b.push_back(0);

//    for(auto i:a)cout<<i<<' ';
//    cout<<endl;
//    for(auto i:b)cout<<i<<' ';
//    cout<<endl;

    vector<int>c;
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        {
            c.push_back(1);
            b[i+1]^=1;
            if(!a[i])
            {
                a[i]=1;
            }
            else
            {
                int st=i;
                while(a[st]==1)
                {
                    a[st]=0;
                    st++;
                }
                a[st]=1;
            }
        }
        else c.push_back(0);
    }
//    for(auto i:c)cout<<i<<' ';
//    cout<<endl;
    puts("3");
    ll ans=0;
    for(int i=0;i<len;i++)
    {
        if(c[i])ans+=two[i];
    }
    printf("%lld ",ans);

    if(a[len]==b[len])puts("0 0");
    else
    {
        if(a[len])
        {
            printf("0 %lld\n",two[len]);
        }
        else printf("%lld %lld\n",two[len-1],two[len-1]);
    }
}

int main()
{
    two[0]=1;
    for(int i=1;i<64;i++)
    {
        two[i]=two[i-1]*2;
    }
//    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        ll x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            ll arr;
            scanf("%lld",&arr);
            x+=arr;
            y^=arr;
        }
        a.clear();
        b.clear();
        y*=2;
        while(x)
        {
            a.push_back(x%2);
            x/=2;
        }
        while(y)
        {
            b.push_back(y%2);
            y/=2;
        }
        solve();
    }
    return 0;
}