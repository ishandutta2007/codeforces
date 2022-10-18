#include<bits/stdc++.h>

using namespace std;

int main()
{
    char h[21],a[21];
    int n;
    scanf("%s%s%d",h,a,&n);
    int kh[100],ka[100];
    memset(kh,0,sizeof(kh));
    memset(ka,0,sizeof(ka));
    for(int i=0;i<n;i++)
    {
        int t,m;
        char c1,c2;
        scanf("%d%*c%c%d%*c%c",&t,&c1,&m,&c2);
        if(c1=='h')
        {
            if(c2=='y')
                kh[m]++;
            else if(kh[m]<2)
                kh[m]=2;
            else kh[m]=3;
            if(kh[m]==2)
                printf("%s %d %d\n",h,m,t);
        }
        else
        {
            if(c2=='y')
                ka[m]++;
            else if(ka[m]<2)
                ka[m]=2;
            else ka[m]=3;
            if(ka[m]==2)
                printf("%s %d %d\n",a,m,t);
        }
    }
}