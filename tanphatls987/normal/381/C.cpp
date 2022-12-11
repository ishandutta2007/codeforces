#include <iostream>
#include <fstream>

using namespace std;

struct setofnum{long int s;int64_t v;};

setofnum a[1000001],cur;
int64_t m,tmp,n,i,next,last;

int trace(long int x,int64_t y);
void solve();
void readfile()
{
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>tmp;
        if (tmp==1) {cin>>a[i].v;a[i].s=0;}
        else cin>>a[i].v>>a[i].s;
    }
    cin>>n;
    next=0;cur.v=0;cur.s=0;
    for(i=0;i<n;i++)
    {last=next; cin>>next; solve();}
}
int main()
{
    readfile();
}
int trace(long int x,int64_t y)
{
    if(!a[x].s) return(a[x].v);
    y=(y+1)%a[x].v;
    if (!y) y=a[x].v;
    x=0;
    while (y>a[x].s*a[x].v)
    {
        if (!a[x].s) y--;else y-=a[x].s*a[x].v;
        x++;
    }
    if ((y==a[x].s*a[x].v)&&(y>0)) {y=0;x++;}
    return(trace(x,y));
}
void solve()
{
    cur.v+=next-last;
    while (cur.v>a[cur.s].s*a[cur.s].v)
    {
        if (!a[cur.s].s) cur.v--;
        else cur.v-=a[cur.s].s*a[cur.s].v;
        cur.s++;
    }
    if ((cur.v==a[cur.s].s*a[cur.s].v)&&(a[cur.s].s>0)) {cur.v=0;cur.s++;};
    cout<<trace(cur.s,cur.v)<<" ";
}