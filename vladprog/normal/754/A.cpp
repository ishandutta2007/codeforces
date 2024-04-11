#include<bits/stdc++.h>

//#define DEBUG

#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG

#define ll long long

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],s=0,l;
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
        ok|=a[i]!=0;
        if(s!=0)
            l=i;
    }
    if(!ok)
        printf("NO\n"),exit(0);
    printf("YES\n");
    if(s!=0)
        printf("1\n1 %d\n",n);
    else
        printf("2\n1 %d\n%d %d\n",l+1,l+2,n);
}