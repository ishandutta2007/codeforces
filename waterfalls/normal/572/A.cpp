#include <cstdio>

using namespace std;

int main() {
int a,b;
scanf("%d%d",&a,&b);
int x,y;
/*for (int i=0;i<a;i++) scanf("%d",&x);
for (int i=a;i<n*/
int k,m;
scanf("%d%d",&k,&m);
for (int i=0;i<k;i++) scanf("%d",&x);
for (int i=k;i<a;i++) scanf("%*d");
for (int i=0;i<=b-m;i++) scanf("%d",&y);
for (int i=b-m;i<b;i++) scanf("%*d");
printf("%s\n",x<y ? "YES" : "NO");
return 0;
}