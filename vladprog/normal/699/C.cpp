#include <bits/stdc++.h>

using namespace std;

const int inf=1000;

int main()
{
    int n;
    scanf("%d",&n);
    int s=0,p=0,v=0;
    //printf("%d : %d %d %d\n",0,0,0,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        int ns,np,nv;
        switch(a)
        {
        case 0:
            ns=inf,np=inf,nv=min(min(s,p),v)+1;
            break;
        case 1:
            ns=inf,np=min(s,v),nv=min(min(s,p),v)+1;
            break;
        case 2:
            ns=min(p,v),np=inf,nv=min(min(s,p),v)+1;
            break;
        case 3:
            ns=min(p,v),np=min(s,v),nv=min(min(s,p),v)+1;
            break;
        }
        s=ns,p=np,v=nv;
        //printf("%d : %d %d %d\n",i,s,p,v);
    }
    printf("%d\n",min(min(s,p),v));
}