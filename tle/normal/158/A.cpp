//zzq
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int n,m,rp[100001],rc=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>rp[i];
    for(int i=1;i<=n;i++)
    {
        if(rp[i]>0&&rp[i]>=rp[m]) rc++;
    }
    cout<<rc;
}