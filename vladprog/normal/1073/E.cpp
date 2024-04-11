#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

#ifndef ONLINE_JUDGE
    #define DEBUG
#endif

#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define all(c) begin(c) , end(c)
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define loop(n) for0(LOOP_COUNTER,n)
#define start_program IFD((start_time=clock()))
#define runtime ((clock()-start_time)*1.0/CLOCKS_PER_SEC)
#define halt(s) cout<<s,IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n",)exit(0)
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // pb_ds
using namespace __gnu_cxx;

#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type, /// null_mapped_type
    class comp=less<key>
>
using ord_set=tree /// find_by_order(), order_of_key()
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

typedef trie
<
    string,
    null_type,
    trie_string_access_traits<>,
    pat_trie_tag,
    trie_prefix_search_node_update
>
pref_trie; /// insert(), prefix_range()

template<class T,class U>
ostream&operator<<(ostream&out,pair<T,U> p)
{
    #ifdef DEBUG
        return out<<"("<<p.x<<","<<p.y<<")";
    #else
        return out<<p.x<<" "<<p.y;
    #endif
}

template<class T,class U>
istream&operator>>(istream&in,pair<T,U> p)
{
    return in>>p.x>>p.y;
}

template<class Iter,class Str>
struct _rng_
{
    Iter from,to;
    Str delim;
    _rng_(Iter from,Iter to,Str delim):from(from),to(to),delim(delim){}
};

template<class Iter,class Str>
_rng_<Iter,Str> rng(Iter from,Iter to,Str delim)
{
    return _rng_<Iter,Str>(from,to,delim);
}

template<class Iter>
auto rng(Iter from,Iter to)
{
    return rng(from,to," ");
}

template<class Cont,class Str>
auto rng(Cont&c,Str delim)
{
    return rng(all(c),delim);
}

template<class Cont>
auto rng(Cont&c)
{
    return rng(all(c));
}

template<class Iter,class Str>
ostream&operator<<(ostream&out,_rng_<Iter,Str> r)
{
    #ifdef DEBUG
        out<<distance(r.from,r.to)<<":"<<r.delim;
    #endif
    for(Iter i=r.from;i!=r.to;i++)
        out<<*i<<r.delim;
    return out;
}

template<class Iter,class Str>
istream&operator>>(istream&in,_rng_<Iter,Str> r)
{
    for(Iter i=r.from;i!=r.to;i++)
        in>>*i;
    return in;
}

template<class T>
T read()
{
    T res;
    cin>>res;
    return res;
}

template<class T>
vector<T> read(int n)
{
    vector<T> res(n);
    cin>>rng(res);
    return res;
}

IFD( clock_t start_time; )

const int MOD=998244353;

ll ppow(ll x,ll y,ll mod)
{
    ll res=1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}

//const int N=;
//const int INF=;

//int a[N];

int k,res_sum[1024][18],res_cnt[1024][18],p[18],pm[18];

int solve_sum(int mask,int cnt);
int solve_cnt(int mask,int cnt);

int solve_sum(int mask,int cnt)
{
    int&ans_sum=res_sum[mask][cnt];
    int&ans_cnt=res_cnt[mask][cnt];
    if(ans_sum>=0)
        return ans_sum;
    if(__builtin_popcount(mask)>k)
        return ans_cnt=0,ans_sum=0;
    if(cnt==0)
        return ans_cnt=1,ans_sum=0;
    ans_sum=ans_cnt=0;
    for0(d,10)
        ans_sum=(ans_sum+solve_sum(!mask&&!d?0:mask|(1<<d),cnt-1)+solve_cnt(!mask&&!d?0:mask|(1<<d),cnt-1)*d%MOD*pm[cnt-1]%MOD)%MOD,
        ans_cnt=(ans_cnt+solve_cnt(!mask&&!d?0:mask|(1<<d),cnt-1))%MOD;
    IFD
    (
        cout<<"( ";
        for0(d,10)
            if(mask&(1<<d))
                cout<<d<<" ";
        cout<<") , "<<cnt<<" -> "<<ans_sum<<" , "<<ans_cnt<<"\n";
    )
    return ans_sum;
}

int solve_cnt(int mask,int cnt)
{
    int&ans_sum=res_sum[mask][cnt];
    int&ans_cnt=res_cnt[mask][cnt];
    if(ans_cnt>=0)
        return ans_cnt;
    if(__builtin_popcount(mask)>k)
        return ans_sum=0,ans_cnt=0;
    if(cnt==0)
        return ans_sum=0,ans_cnt=1;
    ans_sum=ans_cnt=0;
    for0(d,10)
        ans_sum=(ans_sum+solve_sum(!mask&&!d?0:mask|(1<<d),cnt-1)+solve_cnt(!mask&&!d?0:mask|(1<<d),cnt-1)*d%MOD*pm[cnt]%MOD)%MOD,
        ans_cnt=(ans_cnt+solve_cnt(!mask&&!d?0:mask|(1<<d),cnt-1))%MOD;
    IFD
    (
        cout<<"( ";
        for0(d,10)
            if(mask&(1<<d))
                cout<<d<<" ";
        cout<<") , "<<cnt<<" -> "<<ans_sum<<" , "<<ans_cnt<<"\n";
    )
    return ans_cnt;
}


int pref(int x)
{
    int mask=0,ans=0,sum=0;
    ford(cnt,17,0)
    {
        if(x<p[cnt])
            continue;
        int t=x/p[cnt]%10;
        for0(d,t)
            ans=(ans+solve_sum(!mask&&!d?0:mask|(1<<d),cnt)+(sum*10+d)%MOD*solve_cnt(!mask&&!d?0:mask|(1<<d),cnt)%MOD*pm[cnt]%MOD)%MOD;
        mask|=1<<t;
        sum=(sum*10+t)%MOD;
    }
    return (ans+solve_sum(mask,0)+solve_cnt(mask,0)*sum%MOD)%MOD;
}

signed main()
{
    IFN
    (
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    )

    int l,r;
    cin>>l>>r>>k;
    p[0]=pm[0]=1;
    for1(i,17)
        p[i]=p[i-1]*10,pm[i]=p[i]%MOD;
    mem255(res_cnt);
    mem255(res_sum);
    cout<<((pref(r)-pref(l-1))%MOD+MOD)%MOD;

    IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}