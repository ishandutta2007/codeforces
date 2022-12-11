#include <iostream>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    if (n%2) cout<<-1;
    else
    {
        for(i=0;i<n/2;i++) cout<<2*i+2<<" "<<2*i+1<<" ";
    }
}