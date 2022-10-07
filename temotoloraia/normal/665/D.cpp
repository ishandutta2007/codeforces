#include <bits/stdc++.h>
using namespace std;
int n,a[1001],saceri[2000001],prime[2000001],np,i,j,f,x,y;
vector<int>v;
bool check (int k)
{
if (k==1)
return false;
int i,j;
for (i=1;prime[i]*prime[i]<=k && i<=np;i++)
if (k%prime[i]==0)
return false;
return true;
}
int main()
{
cin>>n;
for (i=2;i*i<=2000000;i++)
if (saceri[i]==0)
for (j=i*i;j<=2000000;j+=i)
saceri[j]=1;
for (i=2;i<=2000000;i++)
if (saceri[i]==0)
prime[++np]=i;
for (i=1;i<=n;i++){
cin>>a[i];
if (a[i]==1)
f++;
}
if (f==0){
for (i=0;i<=n;i++)
for (j=i+1;j<=n;j++)
if (i!=j && check(a[i]+a[j])){
if (i!=0){
    cout<<2<<endl;
cout<<a[i]<<" "<<a[j]<<endl;
return 0;
}
x=a[j];
}
if (x==0){
    cout<<1<<endl;
    cout<<a[1]<<endl;
    return 0;
}
cout<<1<<endl;
cout<<x<<endl;
return 0;
}
vector<int>v1;
if (f>=2){
for (i=1;i<=n;i++)
if (a[i]==1)
v1.push_back(a[i]);
for (i=1;i<=n;i++)
if (a[i]>1 && check(a[i]+1)){
    v1.push_back(a[i]);
    break;
}
cout<<v1.size()<<endl;
for (i=0;i<v1.size();i++)
cout<<v1[i]<<" ";
return 0;
}


for (i=0;i<=n;i++)
for (j=i+1;j<=n;j++)
if (i!=j && check(a[i]+a[j])){
if (i!=0){
x=a[i];
y=a[j];
break;
}
if (x==0)
x=a[j];
}
if (x==0){
    cout<<1<<endl;
    cout<<a[1]<<endl;
    return 0;
}
if (y>0)
cout<<2<<endl;
else
cout<<1<<endl;
cout<<x<<" ";
if (y>0)
cout<<y<<endl;
return 0;
}