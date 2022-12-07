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
vector<char> sta1,sta2;
int n,m,i,j,k,t,t1,u,v,a,b;
int c1,c2;
string s,best,cur;
int cnt[26];
int main()
{
	fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>s;
        n=s.size();
        if (s.size()<=2)
        {
            sort(s.begin(),s.end());
            cout<<s<<endl;
            continue;
        }
        best="";
        for (i=0;i<26;i++) cnt[i]=0;
        for (auto g: s) cnt[g-97]++;
        for (i=0;i<26;i++) if (cnt[i]==n) break;
        if (i<26)
        {
            cout<<s<<endl;
            continue;
        }
        //---------------------//
        for (i=0;i<26;i++) if (cnt[i]==1)
        {
            best.push_back(char(i+97));
            for (j=0;j<26;j++) if (i-j) for (k=0;k<cnt[j];k++) best.push_back((char(j+97)));
            break;
        }
        //---------------------//
        if (i<26)
        {
            cout<<best<<endl;
        }
        else
        {
            for (c1=0;c1<26;c1++) {for (c2=0;c2<26;c2++) if ((cnt[c1])and(cnt[c2])and((c1-c2)or((cnt[c1]>=2)and(cnt[c1]-2<=n-cnt[c1])))) break; if (c2<26) break;}
            {
                cnt[c1]--;
                cnt[c2]--;
                cur="";
                cur.push_back(char(c1+97));
                cur.push_back(char(c2+97));
                //-------------------------//
                if (c1>c2)
                {
                    for (i=0;i<26;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                }
                else if (c1<c2)
                {
                    if ((!cnt[c1])or(!cnt[c2]))
                    {
                        for (i=0;i<26;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                    }
                    else
                    {
                        for (u=c1+1;u<c2;u++) if (cnt[u]) break;
                        if (u<c2)
                        {
                            cnt[u]--;
                            for (i=0;i<=c1;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                            cur.push_back(char(u+97));
                            for (i=c1+1;i<26;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                            cnt[u]++;
                        }
                        else
                        {
                            for (u=c2+1;u<26;u++) if (cnt[u]) break;
                            if (u<26)
                            {
                                cnt[u]--;
                                for (i=0;i<=c1;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                                cur.push_back(char(u+97));
                                for (i=c1+1;i<26;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));
                                cnt[u]++;
                            }
                            else
                            {
                                for (i=0;i<c1;i++) for (j=0;j<cnt[i];j++) cur.push_back(char(i+97));

                                for (j=0;j<cnt[c2];j++) cur.push_back(char(c2+97));
                                for (j=0;j<cnt[c1];j++) cur.push_back(char(c1+97));
                            }
                        }
                    }
                }
                else
                {
                    sta1.clear();
                    sta2.clear();
                    for (i=25;i>=0;i--) if (i==c1) for (j=0;j<cnt[i];j++) sta1.push_back(char(c1+97)); else for (j=0;j<cnt[i];j++)  sta2.push_back(char(i+97));
                    //cout<<sta1.size()<<' '<<sta2.size()<<endl;
                    while((sta1.size())or(sta2.size()))
                    {
                    if ((sta1.size())and((sta1.back()<sta2.back())or(sta1.size()==sta2.size()+1))and(sta1.back()!=cur.back()))
                    {
                        cur.push_back(sta1.back());
                        sta1.pop_back();
                    }
                    else
                    {
                        cur.push_back(sta2.back());
                        sta2.pop_back();
                    }
                    }
                }
                //-------------------------//
                if ((cur<best)or(best=="")) best=cur;
                cnt[c1]++;
                cnt[c2]++;
            }
            cout<<best<<endl;
        }
    }
}