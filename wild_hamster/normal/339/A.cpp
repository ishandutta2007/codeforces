#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000009
ll m,n,i,j,k,a[100500],b[100500];
int main()
{
string s;
cin>>s;
n=s.size()/2+1;
for (i=0;i<s.size();i++) if (i%2==0) a[i/2]=(int)s[i]-48;
sort(a,a+n);
for (i=0;i<n-1;i++)
cout<<a[i]<<"+";
cout<<a[n-1]<<endl;
return 0;
}