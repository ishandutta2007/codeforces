#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<utility>
using namespace std;
pair<long long,long long>a[200002];
long long b[200002];
int main()
{
    long long k,m=0,s=0,j=0;
    int i;
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
        if(a[i].first>m)
            m=a[i].first;
        s+=a[i].first;
    }
    sort(a,a+k);
    for(i=0;i<k-1;i++)
    {
        if(a[i].first==(s-2*m))
            b[j++]=a[i].second;
    }
    if(a[k-2].first*2+m==s)
        b[j++]=a[k-1].second;
    cout<<j<<endl;
    if(j)
    {
        for(i=0;i<j-1;i++)
            cout<<b[i]<<'\t';
        cout<<b[j-1];
    }
    else cout<<endl;
    return 0;
}