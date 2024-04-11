#include <iostream>

using namespace std;

int main()
{
    long int h[100001],n,i,x,k;
    cin>>n;
    for(i=0;i<100001;i++) h[i]=-1;
    for(i=0;i<n;i++)
    {
        cin>>x>>k;
        if (x>h[k]) {if (x==h[k]+1) h[k]++;else {cout<<"NO";return 0;}}
    }
    cout<<"YES";
}