#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

const long N=1000005;
const long sqrtN=1005;
const long MOD=1000000007;
char isprime[N];
long Q[N],K[N],sumK[N],sumsK[N],sums2K[N];

long mult(long a, long b);

int main(void) {

  int t;
  scanf("%d",&t);

  for (int i=2;i<N;i++)
    isprime[i]=1;

  for (int i=2;i<sqrtN;i++)
    if (isprime[i])
      for (int j=2*i; j<N; j+=i)
        isprime[j]=0;

  Q[1]=1;

  for (long i=2;i<N;i++) {
    long p=2;
    while (!(i%p==0)) {
      if (p*p>i)
        p=i;
      else
        p++;
    }
    long pk=p;
    long k=1;
    long j=i/p;
    while (j%p==0) {
      k++;
      j/=p;
      pk*=p;
    }
    Q[i]=(k+1)*pk-k*pk/p;
    Q[i]=mult(Q[i],Q[j]);
  }

  for (long i=1;i<N;i++) {
/*    K[i]=(i*(((2*i*i-6*i+1)/3)%MOD)+2*Q[i])%MOD;
    sumK[i]=(sumK[i-1]+K[i])%MOD;
    sumsK[i]=(sumsK[i-1]+i*K[i])%MOD;
    sums2K[i]=(sums2K[i-1]+i*((i*K[i])%MOD))%MOD;*/
    if (i%3==0)
      K[i]=mult(mult(mult(i/3,i),i),2)-mult(2,mult(i,i))+i/3+MOD;
    else if (i%3==1)
      K[i]=mult(mult(i,i),i)-mult(i,mult((i-1)/3,i+1))-mult(2,mult(i,i))+MOD;
    else
      K[i]=mult(mult(i,i),i)-mult(i,mult((i+1)/3,i-1))-mult(2,mult(i,i))+MOD;
    while (K[i]<0)
      K[i]+=MOD;
    K[i]%=MOD;
    K[i]+=mult(2,Q[i]);
    K[i]%=MOD;

    sumK[i]=(sumK[i-1]+K[i])%MOD;
    sumsK[i]=(sumsK[i-1]+mult(i,K[i]))%MOD;
    sums2K[i]=(sums2K[i-1]+mult(mult(i,i),K[i]))%MOD;
  }

  long n,m,mini;
  long res;

  while (t--) {
    scanf("%d %d",&n,&m);
    mini=((n<m) ? n : m);
    n++;
    m++;
//    res=sums2K[mini]-(((n+m)*sumsK[mini])%MOD)+((((n*m)%MOD)*sumK[mini])%MOD)+MOD;
    res=sums2K[mini]-mult(n+m,sumsK[mini])+mult(mult(n,m),sumK[mini]);
    while (res<0) res+=MOD;
    res%=MOD;
    printf("%d\n",res);
//    printf("%d (%d,%d): %d (sums2K %d sumsK %d sumK %d)\n",mini,n,m,res,sums2K[mini],sumsK[mini],sumK[mini]);
  }

  return 0;

}

long mult(long a, long b) {

  long res = 0;
  a%=MOD;
  b%=MOD;
  while (b) {
    if (b&1) {
      res+=a;
      res%=MOD;
    }
    b/=2;
    a*=2;
    a%=MOD;
  }
  return res;

}