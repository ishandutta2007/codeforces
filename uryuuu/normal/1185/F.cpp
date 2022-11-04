#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=550;
const ll Mod=1000000007;

int n,m,k,v,bit,cnt[maxn],b[maxn],c;
vector<pii>s[maxn];
int pos1,pos2;
int cres,res,ccost,cost,mask;
pii ans;
int main()
{
    sync;
    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>k;
        bit=0;
        for(int j=1;j<=k;j++)
        {
            cin>>v;
            v--;
            bit|=(1<<v);
        }
        cnt[bit]++;
    }
    rep(i,1,m)
    {
        cin>>c>>k;
        bit=0;
        rep(j,1,k)
        {
            cin>>v;
            v--;
            bit|=(1<<v);
        }
        s[bit].push_back(pii(c,i));
        sort(s[bit].begin(),s[bit].end());
        while(s[bit].size()>2)
            s[bit].pop_back();
    }
    res=0;
    cost=2*inf+1;
    rep(i,1,maxn-1)
    {
        rep(j,1,maxn-1)
        {
            if(i==j)
            {
                if(s[i].size()<2)
                    continue;
                ccost=s[i][0].first+s[i][1].first;
                pos1=s[i][0].second;
                pos2=s[i][1].second;
            }
            else
            {
                if(!s[i].size()||!s[j].size())
                    continue;
                ccost=s[i][0].first+s[j][0].first;
                pos1=s[i][0].second;
                pos2=s[j][0].second;
            }
            mask=i|j;
            cres=0;
            for(int p=1;p<maxn;p++)
            {
                if((p&mask)==p)
                    cres+=cnt[p];
            }
            if(res<cres||(res==cres&&cost>ccost))
            {
                res=cres;
                cost=ccost;
                ans=pii(pos1,pos2);
            }
        }
    }
    cout<<ans.first<<' '<<ans.second<<endl;
    return 0;
}