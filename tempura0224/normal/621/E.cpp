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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
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
                    ret.a[i * m.w + j] += a[i * w + k] * m.a[k * m.w + j] % mod;
                }
                ret.a[i * m.w + j]%=mod;
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
int main(){
    int n, b, x,k;
    cin>>n>>b>>k>>x;
    vector<int> cnt(10);
    rep(i,n){
        int a;
        cin>>a;
        ++cnt[a];
    }
    Matrix<ll> A(x);
    rep(i,x){
        rep(j,10){
            A.get(i, (10*i + j)%x) += cnt[j];
        }
    }
    Matrix<ll> ret = matpow(A, b);
    cout<<ret.get(0,k)<<endl;
    return 0;
}