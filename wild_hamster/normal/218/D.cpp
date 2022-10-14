#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll k2,k3,r1,z,k4,r,max1,k5,k1,min1,b[1005],n1,n,m,k,i,j;
char a[1005],c;
vector<char > f;
int main()
{
cin>>n>>r;
if (n==1&&r==1) {cout<<0<<endl<<"T";return 0;}
min1=1000001;
for (i=1;i<=(r-1)/2;i++)
{
k1=i;k2=r-i;
k=1;z=0;k3=0;
while (k1!=1)
{
k+=k2/k1;
k3+=k2/k1-1;
k2=k2%k1;
if (k1>1&&k2==0) {z=1;break;}
swap(k1,k2);
}
k+=k2/k1;
k3+=k2/k1-1;
//cout<<i<<" "<<k1<<" "<<k2<<" "<<k<<" "<<z<<" "<<k3<<endl;
if (k3<min1&&k==n&&!z) {min1=k3;r1=i;}
}
if (min1==1000001) {cout<<"IMPOSSIBLE";return 0;}
cout<<min1-1<<endl;
k1=r1;k2=r-r1;c='T';f.push_back(c);
while (k1!=0)
{
if (c=='T') c='B'; else c='T';
if (k1==1&&k2==1) {f.push_back(c);break;}
while (k2>k1) {k2-=k1;f.push_back(c);}
swap(k1,k2);
//cout<<k1<<" "<<k2<<endl;
}
//cout<<i<<" "<<k1<<" "<<k2<<" "<<k<<" "<<z<<" "<<k3<<endl;
if (f[f.size()-1]=='B')
for (i=0;i<f.size();i++)
if (f[i]=='T') f[i]='B'; else f[i]='T';
for (i=f.size()-1;i>=0;i--) cout<<f[i];
return 0;
}