#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
using namespace std;
int k[5],n,i,a[1000005];
int main()
{
cin>>n;
for (i=0;i<5;i++) k[i]=0;
for (i=0;i<n;i++) 
{
cin>>a[i];    
k[i%3]+=a[i];
}
if (k[0]>k[1]&&k[0]>k[2]) cout<<"chest";
else if (k[1]>k[0]&&k[1]>k[2]) cout<<"biceps";
else cout<<"back";
return 0;
}