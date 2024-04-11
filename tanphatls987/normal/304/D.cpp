#include <iostream>
#include <fstream>

using namespace std;

long int ucln(long int,long int);
int main()
{
    long int n,m,x,y,a,b,tmpx,tmpy,x1,x2,y1,y2,tmpab;
    cin>>n>>m>>x>>y>>a>>b;
    tmpab=ucln(a,b);
    a=a/tmpab;b=b/tmpab;
    if ((n/a)<(m/b)) {tmpx=a*(n/a);tmpy=b*(n/a);}
    else {tmpx=a*(m/b);tmpy=b*(m/b);}
    x2=x+tmpx/2;x1=x2-tmpx;
    if (x1<0) {x2=x2-x1;x1=0;};
    if (x2>n) {x1=x1-(x2-n);x2=n;};
    y2=y+tmpy/2;y1=y2-tmpy;
    if (y1<0) {y2=y2-y1;y1=0;};
    if (y2>m) {y1=y1-(y2-m);y2=m;};
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
}
long int ucln(long int k,long int l)
{
    int tmp;
    while (l>0)
    {
        tmp=l;l=k%l;k=tmp;
    }
    return(k);
}