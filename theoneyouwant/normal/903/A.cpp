#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x>0)
        {
            if(x%3==0)
            {
                x=0;
            }
            else
            {
                x=x-7;
            }
        }
        if(x==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}