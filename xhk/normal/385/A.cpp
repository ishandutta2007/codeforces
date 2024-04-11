#include<cstdio>
#include<iostream>
using namespace std;

int n,c,a[110];

int main()
{int i,j,ans=0;
 
 cin>>n>>c;
 
 for(i=1;i<=n;i++) cin>>a[i];
 
 for(i=1;i<n;i++)
   if((a[i]-a[i+1]-c)>ans) 
     ans=a[i]-a[i+1]-c;
 
 cout<<ans<<endl;
 
 return 0;
}