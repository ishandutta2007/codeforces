#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    int sum=0;
    for(int i=1;i<=100;i++)
    {
        if(b[i]!=0)
        {
            sum++;
        }
    }
    if(sum>3)
    {
        cout<<"-1";
        return 0;
    }
    if(sum==1)
    {
        cout<<"0";
        return 0;
    }
    if(sum==2)
    {
        int x=0,y=0;
        for(int i=1;i<=100;i++)
        {
            if(b[i]!=0)
            {
                if(x==0)
                {
                    x=i;
                }
                else
                {
                    y=i;
                }
            }
        }
        if((y-x)%2==0)
        {
            printf("%d",(y-x)/2);
        }
        else
        {
            printf("%d\n",y-x);
        }
    }
    if(sum==3)
    {
        int x=0,y=0,z=0;
        for(int i=1;i<=100;i++)
        {
            if(b[i]!=0)
            {
                if(x==0)
                {
                    x=i;
                }
                else if(y==0)
                {
                    y=i;
                }
                else
                {
                    z=i;
                }
            }
        }
//        printf("%d %d %d\n",x,y,z);
        if(y-x==z-y)
        {
            printf("%d",y-x);
        }
        else
        {
            cout<<"-1\n";
        }
    }
    return 0;
}