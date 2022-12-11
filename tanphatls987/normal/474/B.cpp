#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)

const int N=1e5+10;
int n,q,v,x,a[N];
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&v),a[i]=a[i-1]+v;
    scanf("%d",&q);
    while (q--){
        scanf("%d",&x);
        int l=0,r=n;
        while (l<=r){
            int m=(l+r)>>1;
            if (x<=a[m]) r=m-1;else l=m+1;
        }
        printf("%d\n",l);
    }
}