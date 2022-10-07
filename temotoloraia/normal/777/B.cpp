#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1005],b[1005],ans;
char ch;
main()
{
      cin>>n;
      for (int i=1;i<=n;i++){
          cin>>ch;
          a[i]=ch-'0';
      }
      for (int i=1;i<=n;i++){
          cin>>ch;
          b[i]=ch-'0';
      }
      sort(a+1,a+n+1);
      sort(b+1,b+n+1);
      for (int i=1;i<=n;i++){
          for (int j=i;j<=n;j++)
          if (b[j]>=a[i]){
                          swap(b[i],b[j]);
                          break;
          }
          if (a[i]>b[i])ans++;
      }
      cout<<ans<<endl;
      sort(b+1,b+n+1);
      ans=0;
      for (int i=1;i<=n;i++){
          for (int j=i;j<=n;j++)
          if (b[j]>a[i]){
                          swap(b[i],b[j]);
                          break;
          }
          if (a[i]<b[i])ans++;
      }
      cout<<ans<<endl;
}