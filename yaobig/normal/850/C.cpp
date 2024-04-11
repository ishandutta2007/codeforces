#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> fac;
unordered_map<int,int> sg;

int dfs(int x)
{
    //printf("?? %d\n",x);
    assert(x>0);
    if(x==1) return 0;
    if(sg.find(x)!=sg.end()) return sg[x];
    bool has[35]={};
    int B=0;
    per(i,0,29) if(x&(1<<i)) {B=i;break;}
    rep(i,1,B) has[dfs((x>>i)|(x&((1<<i)-1)))]=1;
    rep(i,0,29) if(!has[i]) {sg[x]=i;break;}
    return sg[x];
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        for(int j=2;1ll*j*j<=x;j++) if(x%j==0)
        {
            int cnt=0;
            while(x%j==0) cnt++,x/=j;
            fac.pb(mp(j,cnt));
        }
        if(x>1) fac.pb(mp(x,1));
    }
    sort(fac.begin(),fac.end());
    int ans=0,now=fac.empty()?-1:fac[0].FI,mask=0;
    for(auto it: fac)
    {
        //printf("%d %d\n",it.FI,it.SE);
        if(it.FI==now) mask|=1<<it.SE;
        else
        {
            ans^=dfs(mask);
            now=it.FI;
            mask=1<<it.SE;
        }
    }
    if(!fac.empty()) ans^=dfs(mask);
    printf("%s\n",ans?"Mojtaba":"Arpa");
    return 0;
}