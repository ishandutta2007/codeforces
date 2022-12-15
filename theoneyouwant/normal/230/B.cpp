#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool a[1000001]={0};
    a[0]=1;a[1]=1;
    for(int i=2;i<1000001;i++)
    {
        if(a[i]==0)
        {
            int j=2;
            while(j*i<=1000000)
            {
                a[j*i]=1;
                j+=1;
            }
        }
    }
    long long int c;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        long long int d = sqrt(c);
        if(d*d == c && a[d]==0)
        {
            cout<<"YES"<<endl;

        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}