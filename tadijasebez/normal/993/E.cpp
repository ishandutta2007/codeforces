#include <stdio.h>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define base complex<db>
const db PI=acos(-1);
vector<base> v;
void fft(vector<base> &a, bool inv)
{
    v.clear();v.resize(a.size());
    int i,j,k;
    for(j=1;j<=a.size();j<<=1)
    {
        db ang=PI*2/j*(inv?-1:1);
        base mul(cos(ang),sin(ang));
        int block=a.size()/j;
        for(i=0;i<block;i++)
        {
            for(k=0;k<j;k++) v[k]=a[k*block+i];
            base cur(1,0);
            for(k=0;k<j/2;k++)
            {
                base tmp1=v[k*2],tmp2=cur*v[k*2+1];
                a[k*block+i]=tmp1+tmp2;
                a[k*block+i+a.size()/2]=tmp1-tmp2;
                cur*=mul;
            }
        }
    }
    if(inv) for(i=0;i<a.size();i++) a[i]/=a.size();
}
void multiply(const vector<ll> &x, const vector<ll> &y, vector<ll> &c)
{
    vector<base> a,b;
    int sz=1,i;
    while(sz<x.size() || sz<y.size()) sz<<=1;
    sz<<=1;a.resize(sz);b.resize(sz);
    for(i=0;i<x.size();i++) a[i]=x[i];
    for(i=0;i<y.size();i++) b[i]=y[i];
    fft(a,0);fft(b,0);
    for(i=0;i<sz;i++) a[i]*=b[i];
    fft(a,1);
    c.clear();c.resize(sz);
    for(i=0;i<sz;i++) c[i]=(ll)(a[i].real()+(a[i].real()>0?0.5:-0.5));
}
const int N=200050;
int a[N];
vector<ll> p,q,r;
int main()
{
    int n,x,i;
    scanf("%i %i",&n,&x);
    p.resize(n+1);q.resize(n+1);
    int sum=0;p[0]++;q[n]++;
    for(i=1;i<=n;i++) scanf("%i",&a[i]),sum+=(a[i]<x),p[sum]++,q[n-sum]++;
    multiply(p,q,r);
    r[n]-=n+1;r[n]/=2;
    for(i=n;i<=2*n;i++) printf("%lld ",r[i]);
    return 0;
}