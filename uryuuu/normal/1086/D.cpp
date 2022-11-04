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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;

set<int>st[3];
int sum[3][maxn];

void upd(int id,int pos,int val)
{
    while(pos<maxn)
    {
        sum[id][pos]+=val;
        pos+=lb(pos);
    }
}

int qry(int id,int pos)
{
    int ans=0;
    while(pos)
    {
        ans+=sum[id][pos];
        pos-=lb(pos);
    }
    return ans;
}


string s; // R 0 P 1 s 2

int ck(char c)
{
    if(c=='R')
        return 0;
    if(c=='P')
        return 1;
    return 2;
}

int a[maxn];
int n,q;

int solve()  // R 0 P 1 s 2
{
    int L,R,l,r;
    int ans=0,id,fk;
    
    for(int i=0;i<=2;i++)
    {
        id=(i+1)%3;
        fk=(i+2)%3;
        if(st[fk].size()==0)
        {
            ans+=qry(id,n)-qry(id,0);
//            cout<<"FUCK"<<' '<<ans<<' ';
            continue;
        }
//        if(st[i].size()==1)
//        {
//            l=*st[fk].begin();
//            r=*st[fk].rbegin();
//
//
//            ans+=qry(id,l);
//            ans+=qry(id,n)-qry(id,r-1);
//        }
        if(st[i].size())
        {
            L=*st[i].begin();
            R=*st[i].rbegin();
            ans+=qry(id,R)-qry(id,L-1);
            
            
            l=*st[fk].begin();
            r=*st[fk].rbegin();
            l=min(l,L);
            r=max(r,R);
            ans+=qry(id,l);
            ans+=qry(id,n)-qry(id,r-1);
        }
//        cout<<i<<' '<<ans<<' ';
    }
    return ans;
}

int main()
{
    sync;
    cin>>n>>q;
    cin>>s;
    int id;
    for(int i=1;i<=n;i++)
    {
        id=ck(s[i-1]);
        a[i]=id;
        upd(id,i,1);
        st[id].insert(i);
    }
    cout<<solve()<<endl;
    int pos;
    char c;
    while(q--)
    {
        cin>>pos>>c;
        id=a[pos];
        st[id].erase(pos);
        upd(id,pos,-1);
        a[pos]=ck(c);
        id=a[pos];
        st[id].insert(pos);
        upd(id,pos,1);
        cout<<solve()<<endl;
    }
    
    return 0;
}