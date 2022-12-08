#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T>
struct Matrix{
    int h,w;
    vector<T> a;
    Matrix(int n_=0):h(n_),w(n_),a(n_*n_){}
    Matrix(int n_, int m_):h(n_),w(m_),a(n_*m_){}
    Matrix(int n_, int m_, vector<T> a_):h(n_),w(m_),a(a_){}
    T& get(int r,int c){return a[r*w+c];}
    T get(int r,int c)const{return a[r*w+c];}

    Matrix& operator+=(const Matrix& m) {
        assert(h == m.h && w == m.w);
        for (int i = 0; i < w*h; ++i)a[i] += m.a[i];
    }
    Matrix& operator-=(const Matrix& m) {
        assert(h == m.h && w == m.w);
        for (int i = 0; i < w*h; ++i)a[i] -= m.a[i];
    }
    Matrix& operator*=(const Matrix& m) {
        assert(w == m.h);
        Matrix ret(h, m.w);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m.w; ++j) {
                for (int k = 0; k < w; ++k) {
                    ret.a[i * m.w + j] += a[i * w + k] * m.a[k * m.w + j]%mod;
                }
            ret.a[i * m.w + j] %= mod;
            }
        }
        return (*this) = ret;
    }
    Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }
    Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }
    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }
};
template<typename T>
Matrix<T> unit(int n){
    Matrix<T> ret(n);
    rep(i,n)ret.get(i,i)=1;
    return ret;
}
template<typename T>
Matrix<T> matpow(Matrix<T> a,int n){
    assert(a.h==a.w);
    Matrix<T> ret=unit<T>(a.h);
    while(n){
        if(n&1)ret*=a;
        a*=a;
        n>>=1;
    }
    return ret;
}

Matrix<ll> a[65];
Matrix<ll> calc(int i, int k){
    return matpow(a[i+k],k-i)*matpow(a[i],i);
}
ll solve(ll n,ll k){
    ll cnt = 0;
    ll tmp = n;
    while(tmp){
        tmp/=k;
        ++cnt;
    }
    Matrix<ll> b[cnt+5],c[cnt+5],d[k+1];
    b[0]=a[k-1];
    c[0]=matpow(b[0],k-1);
    b[1] = calc(k-1, k);
    c[1] = matpow(b[1],k-1);
    Matrix<ll> s = unit<ll>(2*k+1);
    REP(j,2,cnt+2){
        b[j] = calc(k-j%k, k);
        s *= c[j-1];
        b[j] *= s;
        c[j] = matpow(b[j],k-1);
    }
    int idx = 1;
    int rem = n%k;
    n-=rem;
    int q = 0;
    tmp = n;
    if(tmp){while(tmp%k==0){
        ++q;
        tmp/=k;
    }
    }
    q=(k-q%k)%k;
    Matrix<ll> ans = unit<ll>(2*k+1);
    ans = matpow(a[q],rem)*matpow(a[q+k],max(rem-q,0));
    n/=k;
    if(!n){
        return (ans.get(2*k,0)+ans.get(0,0))%mod;
    }
    --n;
    while(n){
        ll t = n%k;
        if(t){
            ans *= matpow(b[idx],t);
        }
        n/=k;
        ++idx;
    }
    ans *= b[1];

    return (ans.get(2*k,0)+ans.get(0,0))%mod;
}
int main(){
    ll n,k;
    cin>>n>>k;
    rep(i,2*k+1){
        a[i]=Matrix<ll>(2*k+1);
        rep(j,i)a[i].get(0,j)=1;
        rep(j,2*k-1)a[i].get(j+1,j)=1;
        a[i].get(2*k,0)=1;
        a[i].get(2*k,2*k)=1;
    }
    cout<<solve(n,k)<<endl;
    return 0;
}