#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,m;
int b[1100],c[1100];
string a;

int main()
{int i,j,k,f;
 
 cin>>n>>m;
 cin>>a;
 
 for(i=1;i<=n;i++) b[i]=a[i-1]-96;
 
 //for(i=1;i<=n;i++) cout<<b[i]<<" ";
 //cout<<endl;
 
 for(i=n-1;i>=0;i--)
 {f=1;
  memset(c,0,sizeof(c));
  for(j=1;j<=i;j++) c[j]=b[j];
  k=b[i+1]+1;
  //cout<<i<<" "<<b[i+1]<<" "<<k<<endl;
  //cout<<i<<" "<<k<<endl;
  while((k==c[i] || k==c[i-1]) && k<=m) k++;
  c[i+1]=k;
  if(k>m) f=0;
  for(j=i+2;j<=n;j++) 
  {k=1;
   while((k==c[j-1] || k==c[j-2]) && k<=m) k++;
   c[j]=k;
   if(k>m) 
   {f=0;
    break;
   }
  }
  if(f==1) break;
 }
 
 if(f==1)
 {for(i=1;i<=n;i++)
    cout<<char(c[i]+96);
  cout<<endl;
 }
 else
  cout<<"NO"<<endl;
 
 return 0;
}