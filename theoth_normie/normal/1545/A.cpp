#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
vector<int> vec;
ordered_set(ll) l1,l2;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[100001];
ll brr[100001];
set<pair<ll,ll>> why;
set<ll> r[2];
ll st;
void check()
{
//    cout<<"------------------------------\n";
//    for (auto g : why)
//    {
    //    cout<<g.fi<<' '<<g.se<<endl;
//    }
//    cout<<"------------------------------\n";
    while ((r[0].size())and(why.size()>1))
    {
        int i=*r[0].begin();
        auto it=why.lower_bound({i,0});
        auto pp=(*it);
        r[pp.se%2].erase(pp.fi);
        {
            auto it2=it;
            it2++;
            if (it2!=why.end())
            {
                r[(it2->se)%2].erase(it2->fi);
                pp.se+=it2->se;
                why.erase(it2);
            }
        }
        {
            auto it2=it;
            if (it2!=why.begin())
            {
                it2--;
                r[(it2->se)%2].erase(it2->fi);
                pp.se+=it2->se;
                why.erase(it2);
            }
            else
            {
                st^=1;
            }
        }
        why.erase(it);
        r[pp.se%2].insert(pp.fi);
        why.insert(pp);
    }
    if ((why.size()==1)and((((why.begin())->se)%2==0)or(st==0))); else u++;
}
int main()
{
	fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        l1.clear();
        l2.clear();
        why.clear();
        r[0].clear();
        r[1].clear();
    cin>>n;
    a=0;
    u=0;
    for (i=1;i<=n;i++) cin>>arr[i];
    for (i=1;i<=n;i++) l2.insert(arr[i]*1e9+i);
    for (i=1;i<=n;i++) 
    {
        l2.erase(arr[i]*1e9+i);
        a=l2.order_of_key(arr[i]*1e9);
        a+=l1.size()-l1.order_of_key(arr[i]*1e9+1e9);
        brr[i]=a%2;
        l1.insert(arr[i]*1e9+i);
    }
        vec.clear();
        for (i=1;i<=n;i++)
        {
            vec.push_back(i);
        }
        sort(vec.begin(),vec.end(),[](int a, int b){
            if (arr[a]-arr[b]) return (arr[a]<arr[b]);
            return (a<b);
        });
        u=0;
        a=0;
        b=0;
        st=brr[vec[0]];
        for (i=0;i<n;i++)
        {  
            
            if ((i)and(arr[vec[i]]-arr[vec[i-1]]))
            {

                
                why.insert({b,a});
                r[a%2].insert(b);
                b++;
                a=0;

                check();
                a=b=0;
                r[0].clear();
                r[1].clear();
                why.clear();

            st=brr[vec[i]];
            }
            else
            if ((i)and(brr[vec[i]]-brr[vec[i-1]]))
            {
                why.insert({b,a});
                r[a%2].insert(b);
                b++;
                a=0;
            }
            a++;
        }
        {
                why.insert({b,a});
                r[a%2].insert(b);
                b++;
                a=0;

                check();
                a=b=0;
                r[0].clear();
                r[1].clear();
                why.clear();
        }
        if (u) cout<<"NO\n"; else cout<<"YES\n";
    }
}