#include <iostream>
using namespace std;

int main()
{
    int n,q,even=0,odd=0;
    long long int total=0;
    cin>>n;
    bool c=0;
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>q;
        if(q>0)
        {
            a[even]+=q;
            even++;
            c=0;
        }
        else
        {
            a[odd]+=q;
            odd++;
            c=1;
        }
        total+=q;
    }
    if(total!=0)
    {
        if(total>0)
        {
            cout<<"first";
        }
        else
        {
            cout<<"second";
        }
    }
    else
    {
        bool z=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                if(a[i]>0)
                {
                    cout<<"first";
                }
                else
                {
                    cout<<"second";
                }
                z=1;
                break;
            }
            
            
        }
        if(z==0)
        {
            if(c==1)
            {
                cout<<"second";
            }
            else
            {
                cout<<"first";
            }
        }
    }
    return 0;
}