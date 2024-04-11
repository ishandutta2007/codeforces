//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;
int n,k,t,sa[100001],sb[100001];
struct tw
{
    int a,b;
    tw(int s,int y) {a=s; b=y;}
};
bool operator < (tw a,tw b)
{
    return a.b<b.b;
}
multiset<tw> wtf;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        wtf.insert(tw(i,t));
    }
    int t=0;
    while(t<k)
    {
        set<tw>::iterator high=wtf.end(),low=wtf.begin();
        high--;
        if(high->b-low->b>=2)
        {
            t++; sa[t]=high->a; sb[t]=low->a;
            tw hp(high->a,high->b-1),lp(low->a,low->b+1);
            wtf.erase(high);
            wtf.erase(low);
            wtf.insert(hp);
            wtf.insert(lp);
        }
        else break;
    }
    set<tw>::iterator high=wtf.end(),low=wtf.begin();
    high--;
    cout<<high->b-low->b<<" "<<t<<"\n";
    for(int i=1;i<=t;i++) cout<<sa[i]<<" "<<sb[i]<<"\n";
    return 0;
}