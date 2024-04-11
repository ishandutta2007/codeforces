#include <iostream>

using namespace std;

int main()
{
    int m,n,a,b,c,p,i,j,x[100000],y[100000],tmp;
    cin>>n>>m>>a>>b>>c>>p;
    for (i=0;i<p;i++) cin>>x[i]>>y[i];
    for(i=0;i<p;i++) switch (a%4)
    {
        case 1:{tmp=x[i];x[i]=y[i];y[i]=n-tmp+1;break;}
        case 2:{x[i]=n-x[i]+1;y[i]=m-y[i]+1;break;}
        case 3:{tmp=x[i];x[i]=m-y[i]+1;y[i]=tmp;break;}
    }
    if (a%2) {tmp=n;n=m;m=tmp;}
    if (b%2) for(i=0;i<p;i++) y[i]=m-y[i]+1;
    for(i=0;i<p;i++) switch (c%4)
    {
        case 3:{tmp=x[i];x[i]=y[i];y[i]=n-tmp+1;break;}
        case 2:{x[i]=n-x[i]+1;y[i]=m-y[i]+1;break;}
        case 1:{tmp=x[i];x[i]=m-y[i]+1;y[i]=tmp;break;}
    }
    for (i=0;i<p;i++) cout<<x[i]<<" "<<y[i]<<endl;
}