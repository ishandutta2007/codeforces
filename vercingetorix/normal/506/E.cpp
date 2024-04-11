#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 10007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 202;
const int B = 8*A+10;
int d[B+5][A][A];
vi pal(B,0);

#define SZ 233333
const int MOD=10007; //or any prime
ll qp(ll a,ll b)
{
    ll x=1; a%=MOD;
    while(b)
    {
        if(b&1) x=x*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return x;
}
namespace linear_seq {
    inline vector<int> BM(vector<int> x)
    {
        //ls: (shortest) relation sequence (after filling zeroes) so far
        //cur: current relation sequence
        vector<int> ls,cur;
        //lf: the position of ls (t')
        //ld: delta of ls (v')
        int lf,ld;
        for(int i=0;i<int(x.size());++i)
        {
            ll t=0;
            //evaluate at position i
            for(int j=0;j<int(cur.size());++j)
                t=(t+x[i-j-1]*(ll)cur[j])%MOD;
            if((t-x[i])%MOD==0) continue; //good so far
            //first non-zero position
            if(!cur.size())
            {
                cur.resize(i+1);
                lf=i; ld=(t-x[i])%MOD;
                continue;
            }
            //cur=cur-c/ld*(x[i]-t)
            ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
            vector<int> c(i-lf-1); //add zeroes in front
            c.pb(k);
            for(int j=0;j<int(ls.size());++j)
                c.pb(-ls[j]*k%MOD);
            if(c.size()<cur.size()) c.resize(cur.size());
            for(int j=0;j<int(cur.size());++j)
                c[j]=(c[j]+cur[j])%MOD;
            //if cur is better than ls, change ls to cur
            if(i-lf+(int)ls.size()>=(int)cur.size())
                ls=cur,lf=i,ld=(t-x[i])%MOD;
            cur=c;
        }
        for(int i=0;i<int(cur.size());++i)
            cur[i]=(cur[i]%MOD+MOD)%MOD;
        return cur;
    }
    int m; //length of recurrence
    //a: first terms
    //h: relation
    ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
    //calculate p*q mod f
    inline void mull(ll*p,ll*q)
    {
        for(int i=0;i<m+m;++i) t_[i]=0;
        for(int i=0;i<m;++i) if(p[i])
            for(int j=0;j<m;++j)
                t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
        for(int i=m+m-1;i>=m;--i) if(t_[i])
            //miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
            for(int j=m-1;~j;--j)
                t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
        for(int i=0;i<m;++i) p[i]=t_[i];
    }
    inline ll calc(ll K)
    {
        for(int i=m;~i;--i)
            s[i]=t[i]=0;
        //init
        s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
        //binary-exponentiation
        while(K)
        {
            if(K&1) mull(s,t);
            mull(t,t); K>>=1;
        }
        ll su=0;
        for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
        return (su%MOD+MOD)%MOD;
    }
    inline int work(vector<int> x,ll n)
    {
        if(n<int(x.size())) return x[n];
        vector<int> v=BM(x); m=v.size(); if(!m) return 0;
        for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
        return calc(n);
    }
}
using linear_seq::work;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[210];
    scanf("%s", c);
    int m;
    string s(c);
    read(m);
    d[0][0][0] = 1;
    int n = s.size();
    forn(i,0,B) forn(l,0,n+1) forn(r,0,n-l+1) {
        if(l+r == n) {
            if(i < B) pal[i] = (pal[i] + d[i][l][r]) % mod;
            if(i+1<B) pal[i+1] = (pal[i+1] + 26*d[i][l][r]) % mod;
            d[i+2][l][r] = (d[i+2][l][r] + 26*d[i][l][r])%mod;
        }
        else if(l+r == n-1) {
            if(i<B) pal[i] = (pal[i] + d[i][l][r]) % mod;
            d[i+2][l][r] = (d[i+2][l][r] + 25*d[i][l][r])%mod;
            d[i+1][l+1][r] = (d[i+1][l+1][r] + d[i][l][r])%mod;
        }
        else if(s[l] == s[n-1-r]) {
            d[i+2][l][r] = (d[i+2][l][r] + 25*d[i][l][r])%mod;
            d[i][l+1][r+1] = (d[i][l+1][r+1] + d[i][l][r])%mod;
        }
        else {
            d[i+2][l][r] = (d[i+2][l][r] + 24*d[i][l][r])%mod;
            d[i+1][l+1][r] = (d[i+1][l+1][r] + d[i][l][r])%mod;
            d[i+1][l][r+1] = (d[i+1][l][r+1] + d[i][l][r])%mod;
        }
    }
    cout<<work(pal, m);
    
    
    
}