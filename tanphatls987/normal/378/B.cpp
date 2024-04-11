#include <iostream>
#include <fstream>
using namespace std;
int n,lc,rc,i,a[100001],b[100001];
int main()
{
   
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    lc=1;rc=1;
    while (lc+rc-2<n) if (a[lc]<b[rc]) lc++;else rc++;
    if (2*lc<=n) lc=n/2;else lc--;
    if (2*rc<=n) rc=n/2;else rc--;
    for(i=1;i<=lc;i++) printf("1");
    for(i=lc+1;i<=n;i++) printf("0");printf("\n");
    for(i=1;i<=rc;i++) printf("1");
    for(i=rc+1;i<=n;i++) printf("0");
}