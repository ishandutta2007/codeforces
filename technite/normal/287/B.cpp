#include<bits/stdc++.h>
using namespace std;
bool solve(long long n,long long x,long long k)
{
    long long num=n-1+x;
    long long mx=((k)*(k+1)/2)-(k-x)*(k-x+1)/2;
    if(num<=mx) return true;
    else return false;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    if(n==1) return cout<<0<<'\n',0;
    long long l=0,r=k-1;
    long long upper=(k)*(k+1)/2;
    upper--;
    if(n-1+k-1>upper) return cout<<-1<<'\n',0;
    while(l<r)
    {
        long long mid=l+(r-l)/2;
        if(solve(n,mid,k)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';

}