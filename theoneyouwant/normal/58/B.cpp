#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<n<<" ";
    for(int i=2;i<=(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
           { cout<<n/i<<" ";
            n=n/i;
           }
        }
    }
    
    return 0;
}