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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
//const ll Mod=1000000007;
const ll Mod=998244353;

map<string,int>mp;

ll sz[100];
string s[100];

string a,b,c,d,e;

ll f(string g)
{
    string h;
    int j;
    int len=g.length();
    ll sum=0;
    for(int i=0;i+3<len;i++)
    {
        h="";
        for(j=0;j<4;j++)
            h+=g[i+j];
        if(h=="haha")
            sum++;
    }
    return sum;
}

string temp;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int tot=0;
        mm(sz);
        int n;
        cin>>n;
        int id;
        for(int i=1;i<=n;i++)
        {
            a="";
            b="";
            c="";
            d="";
            e="";
            cin>>a>>b;
            if(mp[a]==0)
                mp[a]=++tot;
            id=mp[a];
            if(b[0]==':')
            {
                cin>>c;
                sz[id]=f(c);
                temp="";
                temp=c;
                int len=temp.length();
                if(len<=3)
                    s[id]=temp;
                else
                {
                    s[id]="";
                    s[id]+=temp[0];
                    s[id]+=temp[1];
                    s[id]+=temp[2];
                    s[id]+='x';
                    s[id]+=temp[len-3];
                    s[id]+=temp[len-2];
                    s[id]+=temp[len-1];
                }
            }
            else
            {
                cin>>c>>d>>e;
                temp="";
                temp=s[mp[c]]+s[mp[e]];
                sz[id]=sz[mp[c]]+sz[mp[e]];
                sz[id]+=f(temp);
                int len=temp.length();
//                cout<<temp<<' '<<f(temp)<<endl;
                if(len<=3)
                    s[id]=temp;
                else
                {
                    s[id]="";
                    s[id]+=temp[0];
                    s[id]+=temp[1];
                    s[id]+=temp[2];
                    s[id]+='x';
                    s[id]+=temp[len-3];
                    s[id]+=temp[len-2];
                    s[id]+=temp[len-1];
                }
            }
            if(i==n)
            {
                cout<<sz[id]<<endl;
            }
        }
    }
    return 0;
}