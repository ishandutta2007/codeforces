#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int n,m,a,b;

int main()
{int i,j,s1=0,s2=0,s3=0,ans=0;
 
 cin>>n>>m>>a>>b;
 
 s1=(n/m)*b+(n%m)*a;
 s2=n*a;
 s3=((n-1)/m+1)*b;
 
 if(s1<s2)
   ans=s1;
 else
   ans=s2;
   
 if(s3<ans) ans=s3;
 
 cout<<ans<<endl;
 
 return 0;
}