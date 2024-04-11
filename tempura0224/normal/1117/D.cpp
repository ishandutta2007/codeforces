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


Matrix<ll> matpow(Matrix<ll> a,ll n){
    assert(a.h==a.w);
    Matrix<ll> ret(a.h);
    rep(i,a.h)ret.get(i,i)=1;
    while(n){
        if(n&1)ret=ret*a;
        a=a*a;
        n>>=1;
    }
    return ret;
}
int main(){
    ll n,m;
    cin>>n>>m;
    Matrix<ll> A(m);
    rep(i,m-1){
        A.get(i+1, i)=1;
    }
    A.get(0,0)=1;
    A.get(0,m-1)=1;
    auto ret=matpow(A,n);
    cout<<ret.get(0,0)%mod<<endl;

    return 0;
}