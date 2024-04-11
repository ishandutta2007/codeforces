#include <bits/stdc++.h>
using namespace std;
long long n,m,a;
int main()
{
scanf("%lld%lld%lld",&n,&m,&a);
printf("%lld",(long long)(ceil(n/(double)a)*ceil(m/(double)a)));
return 0;
}