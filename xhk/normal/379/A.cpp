#include<cstdio>
#include<iostream>
using namespace std;

int main()
{int a,b,ans=0;
 
 cin>>a>>b;
 
 while(a>=b)
 {ans=ans+(a/b)*b;
  a=a%b+a/b;
 } 
 
 cout<<ans+a<<endl;
 
 return 0;
}