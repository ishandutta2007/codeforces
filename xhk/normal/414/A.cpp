#include<cstdio>
#include<iostream>
using namespace std;

int n,k;

int main()
{//freopen("1.out","w",stdout);
	
 int i,j,s,f;
 
 scanf("%d%d",&n,&k);
 
 if(n==1 & k==0)
 {cout<<1<<endl;
  return 0;
 }
 
 if(k<n/2 || n<2 || (n>=2 && k==0))
 {cout<<-1<<endl;
  return 0;
 }
 
 
 //if(n%2==1)
 //{n--;
 // f=1;
 //}
 
 s=((n-1)/(k-((n-2)/2)))+1;
 
 cout<<(k-((n-2)/2))*s<<" "<<(s+1)*(k-((n-2)/2))<<" ";
 
 for(i=1;i<=n-2;i++) 
 {cout<<i;
  if(i!=n-2) cout<<" ";
  //if(i%100==0) cout<<endl;
 }
 
 
 
 
 //if(f==1)
 //  cout<<" "<<(s+1)*(k-((n-2)/2))+2;//<<endl;
 //else
 //  cout<<endl;
   
 return 0;
}