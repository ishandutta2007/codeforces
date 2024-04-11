#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N=5005;
int n,a[N],b[N],mas[N],ans[N],x;
int go (int k)
{
   if (mas[k])return mas[k];
   mas[k]=1;
   for (int i=0;i<=n;i++)
   if (a[i]>a[k] && b[i]>b[k] && go(i)+1>mas[k]){
      mas[k]=go(i)+1;
      ans[k]=i;
   }
   return mas[k];
}
int main() {
   cin>>n;
   for (int i=0;i<=n;i++)cin>>a[i]>>b[i];
   go(0);
   cout<<mas[0]-1<<endl;
   x=ans[0];
   while (x!=0){
      cout<<x<<" ";
      x=ans[x];
   }
   return 0;
}