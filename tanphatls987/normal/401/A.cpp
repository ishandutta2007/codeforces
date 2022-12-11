#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main()
{
    int i,n,x,tmp;
    int sum=0;
    cin>>n>>x;
    for (i=0;i<n;i++) {cin>>tmp;sum+=tmp;}
    cout<<(((long int)fabs(sum)+x-1)/x);
    return(0);
}