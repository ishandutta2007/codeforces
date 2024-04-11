#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
ll max1,min1,a[100005],b[100005],n1,n,m,k,i,j;
cin>>n>>k;
for (i=0;i<k;i++) {cin>>a[i];b[i]=a[i];}
n1=n;
sort(a,a+k);sort(b,b+k);
max1=0;min1=0;
for (i=0;i<k;i++)
while (n!=0&&a[i]!=0)
{min1+=a[i];a[i]--;n--;}
for (j=0;j<1005;j++)
{
i=k-1;
if (b[i]==0) break;
if (n1==0) break;
while (b[i]==b[i-1]&&i>0&&n1!=0) {max1+=b[i];b[i]--;i--;n1--;}
if (n1!=0) {n1--;max1+=b[i];b[i]--;}
}
cout<<max1<<" "<<min1<<endl;
return 0;
}