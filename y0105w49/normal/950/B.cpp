#include <bits/stdc++.h>
using namespace std;
int main() {
int n,m; scanf("%d%d",&n,&m);
static int a[1<<20],b[1<<20];
for(int i=0;i<n;i++) scanf("%d",a+i);
for(int i=0;i<m;i++) scanf("%d",b+i);
int Z=0;
int x=0,y=0;
int X=0,Y=0;
a[n]=b[m]=38419;
for(;x<n||y<m;) {
if(X<Y) X+=a[x++];
else Y+=b[y++];
if(X==Y) ++Z;
}
printf("%d\n",Z);
}