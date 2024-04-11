#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long n,i,k=-1,m[10000];
vector<long long>v;
void go (long long a4, long long a7, long long a)
{
if (a4+a7<=8)
{
k++;
m[k]=a*10+4;
k++;
go (a4+1,a7,a*10+4);
m[k]=a*10+7;
k++;
go (a4,a7+1,a*10+7);
}
}
int main()
{
cin>>n;
go (0,0,0);
sort(m,m+k);
for (i=510;i<k;i++)
if (n==m[i])
cout<<i-509<<endl;
return 0;
}