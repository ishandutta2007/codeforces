#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second

typedef long long ll;

ll n,a,min1=1e9,max1=-1e9;

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   cin>>n;
   for (int i=0;i<n;i++)
   {
       cin>>a;
       min1=min(min1,a);
       max1=max(max1,a);
   }

   cout<<(min1+max1)/2;
   return 0;
}