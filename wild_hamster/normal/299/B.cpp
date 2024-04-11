#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
long long gcd(long long a,long long b)
{
if (a<b) swap(a,b);
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
string c;
long long z,a[100010],b[100010],min1,m,n,k,i,j,k1,k2,s,rez;
cin>>n>>m;
cin>>c;
k2=0;
while (i<n)
{
k1=0;
while (c[i]=='#') {k1++;i++;}
i++;
if (k1>k2) k2=k1;
}
if (k2>=m) cout<<"NO"<<endl; else cout<<"YES"<<endl;
//system("pause");
return 0;
}