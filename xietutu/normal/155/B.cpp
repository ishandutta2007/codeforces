#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,m,cnt,all,ans,a[1000],b[1000],c[1000];
bool cmp(int x,int y) {
  return(x>y);
}
int main() {
    scanf("%d",&n);
    for (i=0;i!=n;++i) {
      scanf("%d%d",&a[i],&b[i]);
      all+=a[i];cnt+=b[i];
      if (b[i]==0) {c[m]=a[i];++m;}
        else ans+=a[i]; 
    }
    cnt+=1;
    if (cnt>=n) printf("%d",all);
      else {
        sort(c,c+m,cmp);
        for (i=0;i!=cnt-(n-m);++i)
          ans+=c[i];
        printf("%d\n",ans);
      }
}