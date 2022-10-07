#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,a[101],ans;
vector<int>v;
void xmebi ()
{
int i,j;
if (v.size()==0)
cout<<0<<endl;
else
{
sort(v.begin(),v.end());
if (v[v.size()-1]>=a[0])
{
a[0]++;
v[v.size()-1]--;
ans++;
xmebi();
}
else
cout<<ans<<endl;
}
}
main()
{
cin>>n;
for (i=0;i<100;i++)
cin>>a[i];
for (i=1;i<100;i++)
if (a[i]>=a[0])
v.push_back(a[i]);
xmebi();
}