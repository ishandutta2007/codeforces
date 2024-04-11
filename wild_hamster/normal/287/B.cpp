#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#define eps 1e-255
using namespace std;
int main()
{
long long d,i,j,n,k,m,a[5][5],z;
long double rez;
cin>>n>>k;
k--;
if (n==k+2) {cout<<2; return 0;}
if (n==k+1) {cout<<1; return 0;}
if (n==1) {cout<<0;return 0;}
if (n>(k*(k+1))/2+1) {cout<<-1;return 0;}
if (n==(k*(k+1))/2+1) {cout<<k;return 0;}
if (n==(k*(k+1))/2) {cout<<k-1;return 0;}
d=(2*k+1)*(2*k+1)-8*n;
rez=(-2*k+1+sqrt(d))/(-2);
if (abs(rez-(long long)rez)==0) cout<<(long long)rez+1; else
cout<<(long long)rez+2;
return 0;
}