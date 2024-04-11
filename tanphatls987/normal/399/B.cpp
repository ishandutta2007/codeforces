#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    int n,i,l,r;
    int64_t ans=0;
    string a;
    cin>>n;
    cin>>a;
    for(i=n-1;i>=0;i--) {ans*=2;if (a[i]=='B') ans++;}
    cout<<ans;
}