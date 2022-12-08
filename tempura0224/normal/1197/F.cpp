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
const ll mod=998244353 ;


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
Matrix<ll> P[40];


void mult(vector<ll>& v, Matrix<ll>& A){
    int m=v.size();
    vector<ll> nv(m);
    rep(i,m)rep(j,m){
        nv[i]+=A.get(i,j)*v[j]%mod;
    }
    rep(i,m)nv[i]%=mod;
    v.swap(nv);
}
void calc(vector<ll>& v,int n){
    int m = v.size();
    int idx = 0;
    while(n){
        if(n&1){
            vector<ll> nv(m);
            rep(i,m)rep(j,m){
                nv[i]+=P[idx].get(i,j)*v[j]%mod;
            }
            rep(i,m)nv[i]%=mod;
            v.swap(nv);
        }
        n>>=1;
        ++idx;
    }
}

ll dp[1010][4];
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    int m;
    cin>>m;
    vector<pair<int,int>> v[n];
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--z;
        v[x].emplace_back(y,z);
    }
    int f[3][3];
    rep(i,3)rep(j,3)cin>>f[i][j];
    P[0]=Matrix<ll>(64,64);
    rep(i,4)rep(j,4)rep(k,4){
        int cur = 16*i+4*j+k;
        rep(idx,3){
            vector<int> ok(4);
            if(f[idx][0])ok[i]=1;
            if(f[idx][1])ok[j]=1;
            if(f[idx][2])ok[k]=1;
            int nxt=0;
            while(ok[nxt])++nxt;
            P[0].get(16*nxt+4*i+j,cur)+=1;
        }
    }
    Matrix<ll> A[3];
    rep(i,3)A[i]=Matrix<ll>(64,64);
    rep(i,4)rep(j,4)rep(k,4){
        int cur = 16*i+4*j+k;
        rep(idx,3){
            vector<int> ok(4);
            if(f[idx][0])ok[i]=1;
            if(f[idx][1])ok[j]=1;
            if(f[idx][2])ok[k]=1;
            int nxt=0;
            while(ok[nxt])++nxt;
            A[idx].get(16*nxt+4*i+j,cur)+=1;
        }
    }

    rep(i,35){
        P[i+1]=P[i]*P[i];
    }
    rep(i,n){
        vector<ll> res(64);
        res[63]=1;
        int cur = 0;
        sort(v[i].begin(),v[i].end());
        for(auto p : v[i]){
            calc(res,p.first-cur-1);
            mult(res,A[p.second]);
            cur=p.first;
        }
        calc(res,a[i]-cur);
        rep(j,64)(dp[i][j/16]+=res[j])%=mod;
    }
    vector<ll> ans(4);
    ans[0]=1;
    rep(k,n){
        vector<ll> na(4);
        rep(i,4)rep(j,4){
            na[i^j]+=ans[i]*dp[k][j]%mod;
        }
        rep(i,4)na[i]%=mod;
        ans.swap(na);
    }
    cout<<ans[0]<<endl;
    return 0;
}