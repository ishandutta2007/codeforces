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
//#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn = 300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];
int vis[maxn];


int main()
{
    sync;
    
    int s2=0,s4=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[a[i]]++;
        if(vis[a[i]]%2==0)
            s2++;
        if(vis[a[i]]==4)
            s4++;
    }
    int q;
    cin>>q;
    char c;
    int x;
    while(q--)
    {
        cin>>c>>x;
        if(c=='+')
        {
            vis[x]++;
            if(vis[x]%2==0)
                s2++;
            if(vis[x]==4)
                s4++;
        }
        else if(c=='-')
        {
            if(vis[x]%2==0)
                s2--;
            if(vis[x]==4)
                s4--;
            vis[x]--;
        }
        if(s2>=4&&s4>=1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }

    
    
    return 0;
}