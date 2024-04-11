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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

string s;
int pre[maxn],a[maxn];
int vis[30];
struct node
{
    int pos,val;
}b[maxn*10];



int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    int k;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        if(n%k)
        {
            cout<<-1<<endl;
            continue;
        }
        mm(vis);
        
        for(int i=1;i<=n;i++)
        {
            a[i]=ch(s[i-1]);
            vis[a[i]]++;
        }
        int f=0;
        for(int i=1;i<=26;i++)
        {
            if(vis[i]%k)
            {
                f=1;
            }
        }
        if(f==0)
        {
            cout<<s<<endl;
            continue;
        }
        mm(vis);
        
        int sum=0;
        int fk=0;
        int pos=0,val=0;
        int j;
        for(int i=1;i<=n;i++)
        {
            for(j=26;j>a[i];j--)
            {
                fk=sum;
                fk-=(k-vis[j])%k;
                fk+=(k-vis[j]-1)%k;
                if(fk<=n-i)
                {
                    pos=i;
                    val=j;
                }
            }
            sum-=(k-vis[a[i]])%k;
            vis[a[i]]++;
            vis[a[i]]%=k;
            sum+=(k-vis[a[i]])%k;
        }
        if(pos==0)
        {
            cout<<-1<<endl;
            continue;
        }
//        cout<<pos<<' '<<val<<endl;
        mm(vis);
        for(int i=1;i<pos;i++)
        {
            vis[a[i]]++;
            vis[a[i]]%=k;
        }
        vis[val]++;
        vis[val]%=k;
        for(int i=1;i<=26;i++)
        {
            vis[i]=(k-vis[i])%k;
        }
        vis[1]=n-pos;
        for(int i=2;i<=26;i++)
        {
            vis[1]-=vis[i];
        }
        for(int i=1;i<pos;i++)
            cout<<s[i-1];
        cout<<char('a'+(val-1));
        for(int i=1;i<=26;i++)
        {
            for(j=1;j<=vis[i];j++)
                cout<<char('a'+(i-1));
        }
        cout<<endl;
        
    }
    
    return 0;
}