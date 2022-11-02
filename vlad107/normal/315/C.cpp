#include <iostream>
#include <cmath>
#include <algorithm>

long long a[200010];
using namespace std;

int main()
{
    long long n,k,i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long per=1,rez=0,m=0;
    while(per+m<=n)
    {
      rez+=a[per+m]*(per-1);
      if((rez-per*(n-m-per-1)*a[per+m+1])<k)
      {
          cout<<per+m+1<<endl;
          rez-=a[per+m+1]*(per-1);
          m++;
      }
      else
      {
          per++;
      }
    }
    return 0;
}