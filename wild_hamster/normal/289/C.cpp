#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
int s,n,i,j,x,k,k1,k2,a[100000];
cin>>n>>k;
if (n==1&&k==1) {cout<<"a"<<endl;return 0;}
else if (k==1||k>n) {cout<<-1<<endl;return 0;}
for (i=0;i<n-k+2;i++)
if (i%2==0) cout<<"a"; else cout<<"b";
j=0;
for (i=0;i<k-2;i++)
cout<<(char)(99+i);
return 0;
}