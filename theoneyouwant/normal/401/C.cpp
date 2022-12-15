#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m>(2*n+2) || m<n-1)
    {
        cout<<"-1";
    }
    else
    {
        while(m+n !=0)
        {
            if(m==n)
            {
                cout<<"1";
                cout<<"0";
                m--;
                n--;
            }
            else if(m>n)
            {
                if(n!=0)
                
                {cout<<"110";
                m=m-2;
                n=n-1;
                }
                else
                {
                    cout<<"1";
                    m=m-1;
                }
            }
            else if(m==n-1)
            {
                for(int i=0;i<n-1;i++)
                {
                    cout<<"01";
                }
                cout<<"0";
                m=0;n=0;
            }
        }
    }
    return 0;
}