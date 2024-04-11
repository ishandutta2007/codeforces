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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int num[maxn];
vector<int>g[maxn];
multiset<int>st1,st2;
int a[maxn];

int main()
{
    sync;
    int q;
    cin>>q;
    int op;
    int x;
    int id=0;
    int pp;
    
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            id++;
            a[id]=x;
            g[x].push_back(id);
            st1.insert(x);
            st2.insert(id);
        }
        else if(op==2)
        {
            auto pos=st2.begin();
            pp=*pos;
            x=a[pp];
            num[x]++;
            cout<<pp<<' ';
            st2.erase(pos);
            pos=st1.lower_bound(x);
            st1.erase(pos);
        }
        else
        {
            auto pos=st1.end();
            pos--;
            x=*pos;
//            cout<<op<<' '<<x<<' ';
            pp=g[x][num[x]];
            num[x]++;
            cout<<pp<<' ';
            st1.erase(pos);
            pos=st2.lower_bound(pp);
            st2.erase(pos);
        }
    }
    cout<<endl;
    
    return 0;
}