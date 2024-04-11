#include<iostream>
#include<algorithm>
using namespace std;
int a,s,f,g,h,j,k,l,i,n,i1;
pair <int,int>d[100002];
int main()
{
cin>>n>>k;
cin>>g>>h;
for(i=0;i<n;i++)
{
cin>>j>>l;
d[i].first=j*g+h*l;
d[i].second=i+1;
}
sort(d,d+n);
for(i=0;i<n;i++)
{
k=k-d[i].first;
if(k<0) 
{
cout<<i<<endl;
break;
}
}
if(i==n) 
{
cout<<i<<endl;}
for(i1=0;i1<i;i1++)
{
cout<<d[i1].second<<" ";
}
}