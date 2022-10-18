#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int kp=0,km=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)
            kp++;
        else
            km++;
    }
    int ks=min(kp,km)*2;
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int k=r-l+1;
        printf("%d\n",(!(k%2))&&(ks>=k));
    }
}