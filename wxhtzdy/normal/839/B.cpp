#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  scanf("%i%i",&n,&k);
  int a[k*3];
  for(int i=0;i<k;i++) scanf("%i",&a[i]);
  sort(a,a+k);
  reverse(a,a+k);
  int sz4=n,sz2=2*n,sz1=0;
  for(int i=0;i<k;i++){
    while(a[i]>=4&&sz4>0)a[i]-=4,sz4--;
    while(a[i]>=4&&sz2>0)a[i]-=4,sz2-=2;
  }
  for(int i=0;i<k;i++){
    while(a[i]==3&&sz4>0)a[i]=0,sz4--;
    while(a[i]==3&&sz2>1)a[i]=0,sz2-=2;
  }
  int no=0;
  for(int i=0;i<k;i++){
    while(a[i]==2&&sz2>0)a[i]=0,sz2--;
    while(a[i]==2&&sz4>0)a[i]=0,sz4--,sz1++;
    if(a[i]==2) {
      a[i]=1;
      a[k+no]=1;
      no++;
    }
  }
  k+=no;
  for(int i=0;i<k;i++){
    if(a[i]!=1) continue;
    if(sz1>0){
      sz1--;
      a[i]=0;
      continue;
    }
    if(sz2>0) {
      sz2--;
      a[i]=0;
      continue;
    }
    if(sz4>0){
      sz4--;
      sz1++;
      a[i]=0;
      continue;
    }
  }
  bool ok=1;
  for(int i=0;i<k;i++)if(a[i]!=0)ok=0;
  if(ok) printf("YES");
  else printf("NO");
}