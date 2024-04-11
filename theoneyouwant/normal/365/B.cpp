#include<iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n<3)
    {
        cout<<n;
    }
    else
    {
        bool c=0;
        long long int counter=2,max=2;
        for(long long int i=2;i<n;i++)
        {
            if(a[i]==a[i-1]+a[i-2])
            {
                if(c==1)
                {
                    counter++;
                }
                else
                {
                    c=1;
                    counter=3;
                }
            }
            else
            {
                if(c==1)
                {
                    if(counter>max)
                    {
                        max=counter;
                    }
                    counter=0;
                        c=0;
                }
            }
        }
        if(counter>max)
        {
            max=counter;
        }
        cout<<max;
    }
    return 0;
}