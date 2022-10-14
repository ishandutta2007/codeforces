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
ll z,x,y1,y2,m,n,i,j,k,a[100500],b[100500];
int main()
{
string s;
cin>>n;
cin>>s;
k=0;
for (i=0;i<s.size()-1;i++)
if (s[i]==s[i+1]) k++;
cout<<k<<endl;
return 0;
}