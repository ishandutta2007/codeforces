#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int inf=0x3f3f3f3f;
const ll mod=2147493647;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l=inf,r=-inf;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            l=min(l,b);
            r=max(r,a);
        }
//        cout<<l<<

        printf("%d\n",max(0,r-l));
    }
    return 0;
}