#include <iostream>
#include <stdio.h>
using namespace std;
long long gcd(long long a,long long b)
{
if (a<b) swap(a,b);
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
long long z,a[100010],b[100010],min1,m,n,k,i,j,k1,k2,s,rez;
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
if (n==1) {cout<<a[0];return 0;}
min1=(long long)1e+10;
for (i=0;i<n-1;i++)
if (gcd(a[i],a[i+1])<min1) min1=gcd(a[i],a[i+1]);
z=0;
for (i=0;i<n;i++)
if (a[i]==min1) z=1;
if (z==1) cout<<min1<<endl; else cout<<-1<<endl;
//system("pause");
return 0;
}