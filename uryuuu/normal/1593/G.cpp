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
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

string s;
int pre[maxn];
int b[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='['||s[i-1]==']')
            {
                b[++cnt]=i;
                pre[cnt]=pre[cnt-1];
                if(i%2)
                    pre[cnt]++;
                else
                    pre[cnt]--;
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int L,R;
            cin>>L>>R;
            L=lower_bound(b+1,b+cnt+1,L)-b-1;
            R=upper_bound(b+1,b+cnt+1,R)-b-1;
            cout<<abs(pre[R]-pre[L])<<endl;
        }
    }
    return 0;
}