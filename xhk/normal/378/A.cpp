#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{int a,b,i,w=0,p=0,l=0; 
 
 cin>>a>>b;
 
 for(i=1;i<=6;i++)
 {if(fabs(i-a)<fabs(i-b))
    w++;
  else if(fabs(i-a)==fabs(i-b))
    p++;
  else
    l++;
 }
 
 cout<<w<<" "<<p<<" "<<l<<endl;
 
 return 0;
}