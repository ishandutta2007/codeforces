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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1005;
const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>ans[maxn];
int a[maxn*maxn];
string s;

int main()
{
    sync;
    int n,l,k;
    cin>>n>>l>>k;
    cin>>s;
    int m=n*l;
    for(int i=1;i<=m;i++)
    {
        a[i]=int(s[i-1]-'a');
    }
    sort(a+1,a+m+1);
    int L=1,cnt=1;
    while(L<k)
    {
        for(int i=L;i<=k;i++)
        {
            ans[i].push_back(a[cnt++]);
        }
        for(int i=k;i>L;i--)
        {
            if(ans[i].back()>ans[i-1].back())
            {
                L=i;
                break;
            }
        }
        if(ans[k].size()==l)
            break;
    }
    while(ans[k].size()<l)
    {
        ans[k].push_back(a[cnt++]);
    }
    for(int i=1;i<=n;i++)
    {
        while(ans[i].size()<l)
        {
            ans[i].push_back(a[cnt++]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int v:ans[i])
        {
            cout<<char('a'+v);
        }
        cout<<endl;
    }
    return 0;
}