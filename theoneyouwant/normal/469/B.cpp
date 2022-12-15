#include <iostream>
using namespace std;

int main()
{
    int p,q,l,r;
    cin>>p>>q>>l>>r;
    int a[1001]={0},b[1001]={0};
    int c,d;
    for(int i=0;i<p;i++)
    {
        cin>>c>>d;
        for(int j=c;j<d+1;j++)
        {
            a[j]=1;
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>c>>d;
        for(int j=c;j<d+1;j++)
        {
            b[j]=1;
        }
    }
    int counter=0;
    for(int t=l;t<=r;t++)
    {
        bool c=0;
        for(int i=0;i<=1000-t;i++)
        {
            if(b[i]==1 && a[i+t]==1)
            {
                c=1;
                break;
            }
        }
        if(c==1)
        counter++;
    }
    cout<<counter;
    return 0;
}