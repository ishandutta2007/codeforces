#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

struct cp
{
    double x,y;
    cp(){}
    cp(double a,double b){x=a,y=b;}
    inline cp operator + (cp &a) {return cp{x+a.x,y+a.y};}
    inline cp operator - (cp &a) {return cp{x-a.x,y-a.y};}
    inline cp operator * (cp &a) {return cp{x*a.x-y*a.y,x*a.y+y*a.x};}
    inline void operator /= (double a) {x/=a,y/=a;}
    inline void operator += (cp &a) {x+=a.x,y+=a.y;}
    inline cp conj() {return cp(x,-y);}
};
const int maxn = 800005;
const double PI = acos(-1.0);
cp w[maxn], w_inv[maxn];
void init(int n) {
    for(int i=0;i<n;++i) {
        w[i] = cp(cos(2*PI/n*i), sin(2*PI/n*i));
        w_inv[i] = w[i].conj();
    }
}
void fft(cp *a, int n, int f=0) {
    cp *ww;if(f) ww=w;else ww=w_inv;
    for(int i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    for(int l=2;l<=n;l<<=1) {
        int m=l/2;
        for (cp *p=a;p!=a+n;p+=l) {
            for (int i=0;i<m;++i) {
                cp t = ww[n/l*i]*p[m+i];
                p[m+i]=p[i]-t,p[i]+=t;
            }
        }
    }
    if(f) for(int i=0;i<n;++i) a[i]/=n;
}

inline int idx(char c)
{
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='G') return 2;
    return 3;
}
cp a[4][maxn], b[4][maxn];
int c[4][maxn],d[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;++i)
    {
        c[idx(s[i])][max(0,i-k)]++;
        c[idx(s[i])][i+k+1]--;
    }
    for(int j=0;j<4;++j) for(int i=1;i<n;++i) c[j][i]+=c[j][i-1];
    for(int j=0;j<4;++j)
        for(int i=0;i<n;++i)
            if(c[j][i]) a[j][i].x=1;
    reverse(t.begin(), t.end());
    for(int i=0;i<m;++i) b[idx(t[i])][i].x = 1;
    int len=1;for(;len<=n+m;len<<=1);init(len);
    for(int j=0;j<4;++j)
    {
        fft(a[j],len);fft(b[j],len);
        for(int i=0;i<len;++i) a[j][i]=a[j][i]*b[j][i];
        fft(a[j],len,1);
        for(int i=0;i<len;++i) d[i]+=(int)(a[j][i].x+0.5);
    }
    int ans=0;
    for(int i=0;i<len;++i) if(d[i]==m) ans++;
    cout<<ans<<endl;
}