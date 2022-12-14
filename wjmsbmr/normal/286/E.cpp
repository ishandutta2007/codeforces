#include<cstdio>
#include<complex>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef complex<double> cp;
const cp I(0,1);
const double eps=1e-5;
#define N 2111111
int n,m,p[N],S[N],L;bool c[N];
cp a[N],b[N];
void fft(int n,double t,cp *a)
{
    int m,h,i,j,k;
    cp w,x;
    for(m=n,h;h=m/2,m>=2;t*=2,m=h)
        for(i=0;i<h;i++)
            for(w=exp(i*t*I),j=i;j<n;j+=m)
                k=j+h,x=a[j]-a[k],a[j]+=a[k],a[k]=w*x;
    i=0;
    for(j=1;j<n-1;j++)
    {
        for(k=n/2;k>(i^=k);k/=2);
        if(j<i)swap(a[i],a[j]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i),
        a[p[i]]=1,c[p[i]]=1;
    int n2=1<<21;
    fft(n2,2*M_PI/n2,a);
    for(int i=0;i<n2;i++)b[i]=a[i]*a[i];
    fft(n2,-2*M_PI/n2,b);
    for(int i=1;i<=m;i++)
        if(fabs(b[i].real())>0.5*n2&&!c[i]){puts("NO");return 0;}
    for(int i=1;i<=m;i++)
        if(fabs(b[i].real())<0.5*n2&&c[i])S[++L]=i;
    puts("YES");
    printf("%d\n",L);
    for(int i=1;i<=L;i++)
        printf("%d%c",S[i],i==L?'\n':' ');
    return 0;
}