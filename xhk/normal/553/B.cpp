#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

long long flag=0;
long long n,m;
long long a[100];

int main()
{long long i,j,k,last;
 
 a[0]=1;
 for(i=1;i<=50;i++)
    a[i]=a[i-1]+a[i-2];
 
 /*
 for(i=1;i<=50;i++)
    cout<<a[i]<<endl;   
 */

 cin>>n>>m;
 
 for(i=1;i<=n;i++)
 {  if(m>a[n-i+1-1] && i<n)
    {   m-=a[n-i+1-1];
        if(flag!=0)
            cout<<" ";
        else
            flag=1;
        cout<<i+1<<" "<<i;
        i++;
    }
    else
    {   if(flag!=0)
            cout<<" ";
        else
            flag=1;
        cout<<i;
    }
 }
 
 cout<<endl;
 
 return 0;
}