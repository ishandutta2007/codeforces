#include <bits/stdc++.h>
using namespace std;
int main()
{
int l,r,a;
scanf("%i%i%i",&l,&r,&a);
int ans=0;
for(int i=0;i<205;i++)
if(max(0,i-l)+max(0,i-r)<=a)ans=i;
printf("%i",ans*2);
}