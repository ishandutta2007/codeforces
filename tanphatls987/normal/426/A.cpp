#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,k,a[100],i,sum,maxv,tmp;
    cin>>n>>k;
    sum=0;maxv=0;
    for(i=0;i<n;i++) {cin>>tmp;if (tmp>maxv) maxv=tmp;sum+=tmp;}
    sum-=maxv;
    if (sum>k) cout<<"NO";else cout<<"YES";
}