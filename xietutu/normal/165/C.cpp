#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int pos[1000005],k,m,n,t;
long long ans;
char s[1000005];
int main() {
    scanf("%d",&k); scanf("%s",s);
    n=strlen(s);
    for (int i=0;i!=n;++i) 
        if (s[i]=='1')  pos[++m]=i; 
    pos[m+1]=n;pos[0]=-1;
    if (k==0) {
      for (int i=1;i<=m+1;++i) {
        t=(pos[i]-pos[i-1]-1);
        ans+=static_cast<long long>(t)*(t+1)/2;
      }
    }
    else {
      for (int i=1;i<=m-k+1;++i) 
        ans+=static_cast<long long>(pos[i]-pos[i-1])*(pos[i+k]-pos[i+k-1]);
    }
    printf("%I64d",ans);
}