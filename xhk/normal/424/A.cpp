#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

string s;

int n;

int main()
{int i,j,s1=0,s2=0,s3=0,l=0,f=0;

 cin>>l;
 cin>>s;
 
 //l=s.length();
 
 for(i=0;i<l;i++)
   if(s[i]=='x')
     s1++;
   else
     s2++;
 
 s3=(fabs(s1-s2))/2;
 
 cout<<s3<<endl;
 
 //cout<<s1<<" "<<s2<<endl;
 
 i=0;
 f=0;   
 while(f<s3 && i<l)
 {//cout<<i<<" "<<f<<" "<<l<<" "<<s[i]<<endl;
  if(s1>s2 && s[i]=='x')
  {cout<<'X';
   f++;
  }
  else if(s1<s2 && s[i]=='X')
  {cout<<'x';
   f++;
  }
  else
    cout<<s[i];
  
  i++;
 }
 
 while(i<l) 
 {cout<<s[i];
  i++;
 }
 
 cout<<endl;
 
 return 0;
}