#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct node
{
    int l,r;
    node(){}
    node(int a,int b):l(a),r(b){}
}s[maxn+5];
bool cmp(node a,node b) {return a.l<b.l;}
multiset<int> S;

int main()
{
    int n,x,y; scanf("%d%d%d",&n,&x,&y);
    rep(i,1,n) scanf("%d%d",&s[i].l,&s[i].r);
    sort(s+1,s+n+1,cmp);

    ll ans=0;
    rep(i,1,n)
    {
        bool flag=0;
        if(!S.empty())
        {
            multiset<int>::iterator it=S.upper_bound(s[i].l);
            if(it!=S.begin())
            {
                it--;
                int tmp=*it;
                if(1ll*(s[i].l-tmp+1)*y<x)
                {
                    flag=1;
                    S.erase(it);
                    ans=(ans+1ll*(s[i].r-tmp+1)*y)%mod;
                    S.insert(s[i].r+1);
                    //printf("%d: Old : %d %d %I64d\n",i,s[i].l,s[i].r,ans);
                }
            }
        }
        if(flag==0)
        {
            ans=(ans+x+1ll*y*(s[i].r-s[i].l))%mod;
            S.insert(s[i].r+1);
            //printf("%d: New : %d %d %I64d %I64d\n",i,s[i].l,s[i].r,ans,x+1ll*y*(s[i].r-s[i].l));
        }
    }
    printf("%I64d\n",ans);
    return 0;
}