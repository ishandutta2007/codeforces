#include<bits/stdc++.h>

using namespace std;

void add(int l,int r)
{
    //printf("add( %d , %d )\n",l,r);
    printf("1 %d\n",l);
    for(int i=l;i<=r-1;i++)
        printf("%d %d\n",i,i+1);
    //printf("\n");
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int d=(n-1)/k,kp=(n-1-d*k),km=k-kp;
    switch(kp)
    {
        case 0 :printf("%d\n",d*2  );break;
        case 1 :printf("%d\n",d*2+1);break;
        default:printf("%d\n",d*2+2);break;
    }
    //printf("d=%d kp=%d km=%d\n",d,kp,km);
    int p=1;
    for(int i=1;i<=kp;i++)
        add(p+1,p+d+1),p=p+d+1;
    for(int i=1;i<=km;i++)
        add(p+1,p+d),p=p+d;
}