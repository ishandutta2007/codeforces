#include <iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
    long int n,k,i,j;
    cin>>n>>k;
    if (k<=(n-1)/2)
    {
        cout<<n*k<<endl;
        for(i=1;i<=n;i++)
            for(j=0;j<k;j++) cout<<i<<" "<<((i+j)%n)+1<<endl;
    }
    else cout<<-1;
}