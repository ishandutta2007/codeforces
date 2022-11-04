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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn];
int pos[maxn];
int pre[4][maxn];
string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        s="";
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            a[i]=ch(s[i-1]);
        }
        int j;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)
                pre[j][i]=pre[j][i-1];
            pre[a[i]][i]++;
            if(a[i]==1)
                pos[++cnt]=i;
        }
        int mn=1e8;
        int lenb,lenc;
        int id;
        for(int i=2;i<=cnt;i++)
        {
            id=pos[i];
            lenb=pre[2][id]-pre[2][pos[i-1]-1];
            lenc=pre[3][id]-pre[3][pos[i-1]-1];
            if(lenb<2&&lenc<2)
            {
                mn=min(mn,pos[i]-pos[i-1]+1);
            }
            if(i==2)
                continue;
            lenb=pre[2][id]-pre[2][pos[i-2]-1];
            lenc=pre[3][id]-pre[3][pos[i-2]-1];
            if(lenb<3&&lenc<3)
            {
                mn=min(mn,pos[i]-pos[i-2]+1);
            }
        }
        if(mn==1e8)
            cout<<-1<<endl;
        else
            cout<<mn<<endl;
    }
    return 0;
}