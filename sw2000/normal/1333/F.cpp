#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ma[N];
int main()
{
    for(int i=1;i<N;i++)
        for(int j=i*2;j<N;j+=i)
            ma[j]=i;
    int n;cin>>n;
    sort(ma+2,ma+1+n);
    for(int i=2;i<=n;i++)
        cout<<ma[i]<<' ';
    return 0;
}