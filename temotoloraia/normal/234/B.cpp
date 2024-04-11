#include <bits/stdc++.h>
using namespace std;
int n,k,a[1001],b[1001],i,j;
vector<int>v;
main()
{
ifstream ifs ("input.txt");
ofstream ofs ("output.txt");
ifs>>n>>k;
for (i=0;i<n;i++){
ifs>>a[i];
b[i]=a[i];
}
sort(b,b+n);
ofs<<b[n-k]<<endl;
for (i=0;i<n;i++)
if (a[i]>b[n-k])
v.push_back(i+1);
for (i=0;i<n && v.size()<=k;i++)
if (a[i]==b[n-k])
v.push_back(i+1);
sort(v.begin(),v.end());
for (i=0;i<k;i++)
ofs<<v[i]<<" ";
}