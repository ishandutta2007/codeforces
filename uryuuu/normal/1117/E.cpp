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
const ll Mod=998244353;


string s;

struct node
{
    int x,y,z;
}a[maxn];

string b,c,d;

int ans[maxn];

int main()
{
    cin>>s;
    int n=s.length();
    for(int i=1;i<=n;i++)
    {
        a[i].x=(i/26)/26;
        a[i].y=(i/26)%26;
        a[i].z=i%26;
    }
    cout<<"? ";
    for(int i=1;i<=n;i++)
    {
        cout<<char('a'+a[i].x);
    }
    cout<<endl;
    cin>>b;
    
    cout<<"? ";
    for(int i=1;i<=n;i++)
    {
        cout<<char('a'+a[i].y);
    }
    cout<<endl;
    cin>>c;
    
    cout<<"? ";
    for(int i=1;i<=n;i++)
    {
        cout<<char('a'+a[i].z);
    }
    cout<<endl;
    cin>>d;
    
    int pos;
    for(int i=1;i<=n;i++)
    {
        pos=26*26*(b[i-1]-'a')+26*(c[i-1]-'a')+(d[i-1]-'a');
        ans[pos]=i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)
    {
        cout<<s[ans[i]-1];
    }
    cout<<endl;
    
    return 0;
}