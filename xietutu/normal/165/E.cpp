#include <cstdio>
#include <cstring>
#include <cstdlib>
const int inf=0x3FFFFF;
int d[inf+1],n,a[1000001];
int main() {
    memset(d,255,sizeof(d));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        d[a[i]^inf]=a[i];
    }
    for (int i=inf;i>=0;--i) 
        if (d[i]!=-1) {
          for (int j=0;j<22;++j) 
            if (i&(1<<j)) 
              d[i^(1<<j)]=d[i];
        } 
    for (int i=1;i<=n;++i) 
      if (d[a[i]]==-1) printf("-1 ");
        else printf("%d ",d[a[i]]);
}