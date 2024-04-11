#include <iostream>
using namespace std;
const int64_t maxi=1000000000;
int main()
{
    int64_t n,k,tmp,i;
    cin>>n>>k;
    if ((k<(n/2))||(k>((n/2)*maxi))) {cout<<-1;return 0;}
    tmp=1;
    if (n>=2)
    {tmp=k-n/2+1;
    cout<<tmp<<" "<<2*tmp<<" ";
    n-=2;}
    if ((tmp<=n)&&(maxi-2*tmp-1>=n)) tmp=2*tmp+1;else tmp=1;
    for (i=tmp;i<=tmp+n-1;i++) cout<<i<<" ";
}