#include <stdio.h>
#include <algorithm>
using namespace std;
struct Segment
{
long long ss,se;
bool operator < (const Segment &b) const
{
if(ss==b.ss) return se<b.se;
return ss<b.ss;
}
} segments[100007];
int main()
{
int n,i;
long long x1,x2,k,nn;
scanf("%i",&n);
scanf("%lld %lld",&x1,&x2);
for(i=0;i<n;i++)
{
scanf("%lld %lld",&k,&nn);
long long y1=k*x1+nn;
long long y2=k*x2+nn;
segments[i].ss=y1;
segments[i].se=y2;
}
sort(segments,segments+n);
bool ok=false;
for(i=1;i<n;i++)
{
if(!(segments[i-1].se<=segments[i].se)) ok=true;
}
if(ok) printf("YES\n");
else printf("NO\n");
return 0;
}