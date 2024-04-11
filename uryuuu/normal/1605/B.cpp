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
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

string s;

vector<int>ans[1005];
int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        s="";
        int n;
        cin>>n;
        cin>>s;
        for(int i=1;i<=n;i++)
            ans[i].clear();
        for(int i=1;i<=n;i++)
        {
            a[i]=int(s[i-1]-'0');
        }
        int cnt=0;
        int L,R;
        int fl=0;
        while(1)
        {
            fl=0;
            for(int i=2;i<=n;i++)
            {
                if(a[i-1]>a[i])
                    fl=1;
            }
            if(fl==0)
                break;
            cnt++;
            L=1;R=n;
            while(1)
            {
                while(L<R)
                {
                    if(a[L]==1)
                        break;
                    L++;
                }
                if(L>=R)
                    break;
                while(L<R)
                {
                    if(a[R]==0)
                        break;
                    R--;
                }
                if(L>=R)
                    break;
                ans[cnt].push_back(L);
                ans[cnt].push_back(R);
                swap(a[L],a[R]);
                L++;
                R--;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
        {
            sort(ans[i].begin(),ans[i].end());
            cout<<ans[i].size()<<' ';
            for(int v:ans[i])
                cout<<v<<' ';
            cout<<endl;
        }
    }
    return 0;
}