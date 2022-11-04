#include<cstdio>
#include<iostream>
using namespace std;

/*
struct unit
{int t,w;
};
struct unit l[200010],r[200010];
*/

int n,ls=0,rs=0,c[200010],l[200010],r[200010],l1[200010],r1[200010];

int main()
{int i,j;
 long long ans=0;
 
 
 cin>>n;
 
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 
 for(i=n;i>=1;i--) 
   if(c[i]==0)
     l[i]=l[i+1]+1;
   else
     l[i]=l[i+1];
 
 //cout<<"h";
 
 for(i=1;i<=n;i++)
   if(c[i]==1)
     r[i]=r[i-1]+1;
   else
     r[i]=r[i-1];          
 
 //cout<<"g";
 
 i=1;
 while(c[i]==0 && i<=n) i++;
 j=n;
 while(c[i]==1 && j>=1) j--;
 
 while(i<=n || j>=1)
 {if(i<=n && (n-i-rs>j-1-ls || j<1))
  {ans=ans+l[i+1]-ls;
   r1[i]=-1;
   rs++;
   ls=ls+l1[i];
   i++;
   while(c[i]==0 && i<=n) i++;
  }
  else
  {ans=ans+r[j-1]-rs;
   l1[j]=-1;
   ls++;
   rs=rs+r1[j];
   j--;
   while(c[j]==1 && j>=1) j--;
  }
  //cout<<i<<" "<<j<<endl;
 }
 
 cout<<ans<<endl;
 
 return 0;
}