#pragma G++ optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int n;main(){
for(int i=1;i<=10000000;i++) a[i]=rand();
sort(a+1,a+10000001);
for(scanf("%d",&n);n--;printf("%d",n%2));}