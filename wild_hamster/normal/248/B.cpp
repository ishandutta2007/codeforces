#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll s,m,k1,k2,k3,k4,j,n,i,i1,i2,i3,max1,a[200200];
int main()
{
cin>>n;
if (n==1||n==2) {cout<<-1;return 0;}
if (n==3) {cout<<210;return 0;}
cout<<1;
for (i=0;i<n-4;i++) cout<<0;
if (n%6==0) cout<<170; else
if (n%6==1) cout<<"020"; else
if (n%6==2) cout<<200; else
if (n%6==3) cout<<110; else
if (n%6==4) cout<<"050"; else
cout<<"080";
return 0;
}