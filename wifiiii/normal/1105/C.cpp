#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;
const ll N = 3;
struct Matrix {
    #define rep(i, n) for(int i = 0; i < n; i++)
    #define clr(a, b) memset(a, b, sizeof a)
    ll e[N][N];
    int sz;
    Matrix(int _sz): sz(_sz){ clr(e, 0);}
    ll * operator[] (int i) { return e[i];}
    void E() { rep(i, sz) e[i][i] = 1;}
    Matrix operator * (Matrix &R)const {
        Matrix ret(sz);
        rep(i, sz) rep(j, sz) rep(k, sz)
            (ret[i][j] += e[i][k]  * R[k][j]) %= mod;
        return ret;
    }
    Matrix operator ^ (ll n) const{
        Matrix ret(sz), a = *this;
        ret.E();
        while(n) {
            if(n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        return ret;
    }
};
int main()
{
    int n,l,r;
    cin>>n>>l>>r;
    ll a=0,b=0,c=0;
    if(r-l<10)
    {
        for(int i=l;i<=r;++i)
        {
            if(i%3==1) b++;
            if(i%3==2) c++;
            if(i%3==0) a++;
        }
    } else
    {
        while(l%3!=0&&l<=r)
        {
            if(l%3==1) b++;
            if(l%3==2) c++;
            l++;
        }
        while(r%3!=0&&l<=r)
        {
            if(r%3==1) b++;
            if(r%3==2) c++;
            r--;
        }
        a+=(r-l)/3+1,b+=(r-l)/3,c+=(r-l)/3;
    }
    if(n==1)
    {
        cout << c << endl;
        return 0;
    }
    Matrix m(3);
    m[0][0] = a, m[0][1] = c, m[0][2] = b;
    m[1][0] = b, m[1][1] = a, m[1][2] = c;
    m[2][0] = c, m[2][1] = b, m[2][2] = a;
    m = m^(n-1);
    ll ans = a*m[0][0]+b*m[0][1];
    ans %= mod;
    ans += c*m[0][2];
    ans %= mod;
    while(ans<0) ans+=mod;
    cout << ans << endl;
}