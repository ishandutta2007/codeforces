#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
int n;
double k1,k2,k3;
cin>>n;
cin>>k1;
k2=k1;k3=k1;
n--;
while (n>0)
{
n--;
cin>>k1;
k3+=(2*k2+1)*k1;
k2=(k2+1)*k1;
}
printf("%.10f", k3);
return 0;
}