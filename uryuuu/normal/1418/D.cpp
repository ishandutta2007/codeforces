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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=3000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
//#define int long long

set<ll>st;
multiset<ll>st2;

void pt()
{
    if(st.size()<=3)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<*++st.rbegin()-*++st.begin()-*++++st2.rbegin()<<endl;
    }
}

int main()
{
    sync;
    int n,q;
    cin>>n>>q;
    ll x;
    st.insert(1ll*-1e16);
    st.insert(1ll*1e16);
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        st.insert(x);
    }
    for(auto i=st.begin();i!=st.end();i++)
    {
        auto j=next(i);
        if(j!=st.end())
            st2.insert(*j-*i);
    }
    pt();
    int op;
    while(q--)
    {
        cin>>op>>x;
        if(op==0)
        {
            auto pos=st.lower_bound(x);
            st2.erase(st2.lower_bound(*pos-*prev(pos)));
            st2.erase(st2.lower_bound(*next(pos)-*pos));
            st2.insert(*next(pos)-*prev(pos));
            st.erase(pos);
        }
        else
        {
            if(st.count(x)==0)
            {
                auto pos=st.insert(x).first;
                st2.erase(st2.lower_bound(*next(pos)-*prev(pos)));
                st2.insert(*pos-*prev(pos));
                st2.insert(*next(pos)-*pos);
//                cout<<*pos-*prev(pos)<<endl;
            }
        }
//        for(auto i:st)
//            cout<<i<<' ';
//        cout<<endl;
//        for(auto i:st2)
//            cout<<i<<' ';
//        cout<<endl;
        pt();
    }
    
    return 0;
}