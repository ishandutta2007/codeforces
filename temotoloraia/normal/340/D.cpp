#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,a[1000001],b[1000001],i,j,np=1,l,r,c,ans;
int main() {
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    b[1]=a[1];
    for (i=2;i<=n;i++)
        {
        l=1;
        r=np;
        ans=0;
        while (l<=r)
            {
            c=(l+r)/2;
            if (b[c]<a[i]){
                l=c+1;
                ans=c;
            }
            else if (b[c]==a[i])
                {
                ans=c-1;
                break;
            }
            else
                r=c-1;
        }
        if (b[ans+1]==0)
            np++;
        if (b[ans+1]==0 || b[ans+1]>=a[i])
            b[ans+1]=a[i];
    }
    for (i=n;i>=1;i--)
        if (b[i]>0)
        break;
    cout<<i<<endl;
    return 0;
}