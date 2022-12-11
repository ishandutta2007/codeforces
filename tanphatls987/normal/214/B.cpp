#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long int a[10]={0};
    long int n,t,i,tmp,j,key;
    cin>>n;
    t=0;key=0;
    for(i=0;i<n;i++) {cin>>tmp;a[tmp]++;t+=tmp;}
    if (t%3==1)
        {for(i=1;i<=9;i+=3) if (a[i]>=1) {a[i]--;t--;break;}
          if (t%3) for(i=2;i<=9;i+=3) while ((t%3)&&(a[i]>0)) {a[i]--;t-=2;}
        }else
    if (t%3==2)
        {for(i=2;i<=9;i+=3) if (a[i]>=1) {a[i]--;t-=2;break;}
          if (t%3) for(i=1;i<=9;i+=3) while((t%3)&&(a[i]>0)) {a[i]--;t-=1;}
        }
    if ((t%3==0)&&(a[0]>0))
    {
        for(i=9;i>0;i--)
            {for(j=0;j<a[i];j++) cout<<i;if (a[i]>0) key=1;}
        if (key==1) for (i=0;i<a[0];i++) cout<<0;else cout<<0;
    }

    else cout<<-1;
}