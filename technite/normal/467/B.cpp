#include<iostream>
using namespace std;
int n,m,k,i,a[10005],s;
int main()
{
    int n,m,k,i,s=0;
cin>>n>>m>>k;
int a[m+1];
for(;i<m+1;i++)cin>>a[i];
for(i=0;i<m;i++){
if(__builtin_popcount(a[m]^a[i])<=k)s++;
}
cout<<s;

}