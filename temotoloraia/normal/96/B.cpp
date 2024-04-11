#include <iostream>
using namespace std;

long long n,res;

void rec(long long x,int cnt7,int cnt4)
{
 if ( x>=n ) if ( cnt7==cnt4 ) if ( res==0 || x<res ) res=x; 
 if ( x<n*100 )
  {
   rec(x*10+4,cnt7,cnt4+1);
   rec(x*10+7,cnt7+1,cnt4);
  }
}


main()
{
 cin>>n;
 rec(0,0,0);
 if ( n==0 ) { res=47; };
 cout<<res;
}