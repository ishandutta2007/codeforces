#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#define tr 1000000007
using namespace std;
bool f(int a, int b, int c)
{
while (a!=0)
{
if (a%10!=b&&a%10!=c) return false;
a/=10;
}
return true;
}
long long binpow (long long a, long long n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return ((long long)binpow (a, n-1) * a)%tr;
    else {
        int b = binpow (a, n/2);
        return ((long long)b * b)%tr;
    }
}
long long a[1000005],b[1000005],c[1000005],d[1000005],m,k11,k12,k13,n,i,j,k,k1,k2,k3;
int main()
{
cin>>k1>>k2>>n;
k=k1*n;
for (i=0;i<=n;i++)
{
if (f(k,k1,k2)) c[i]=1; else c[i]=0;
k+=k2-k1;
}
a[1]=1;
for (i=2;i<=n;i++)
a[i]=(a[i-1]*i)%tr;
k=0;
/*for (i=0;i<=n;i++)
cout<<c[i]<<" ";
cout<<endl;*/
for (i=0;i<=n;i++)
if ((c[i]==1&&i==0)||(c[i]==1&&i==n)) k+=1; else
if (c[i]==1) k=(k+(a[n]*binpow((long long)(a[i]*a[n-i])%tr,tr-2))%tr)%tr;
cout<<k%tr;
//system("pause");
return 0;
}