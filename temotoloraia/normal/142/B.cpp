#include <iostream>
using namespace std;
int n,m;
main()
{
cin>>n>>m;
if (n<2 || m<2) cout<<m*n;
else if ((n==2 && m%2!=0) || (m==2 && n%2!=0)) cout<<(n*m+1)/2+1;
else if ((n==2 && m%4!=0) || (m==2 && n%4!=0)) cout<<(n*m+1)/2+2;
else cout<<(n*m+1)/2; 
}