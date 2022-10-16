#include<bits/stdc++.h>
using namespace std;
void printarray(int a[], int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void printvector(vector<int> v)
{
    for (auto x : v)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n),prefix(n+1),suffix(n+1);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
    }
    long long g1=v[1],g2=v[n-2];
    prefix[0]=v[0];
    for(int i=1;i<n;i++)
    {
        g1=__gcd(g1,v[i]);
        prefix[i]=__gcd(prefix[i-1],v[i]);
    }
    suffix[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        g2=__gcd(g2,v[i]);
        suffix[i]=__gcd(suffix[i+1],v[i]);
    }
    long long ans=g1*g2/__gcd(g1,g2);
    for(int i=1;i<n-1;i++)
    {
        long long c=__gcd(prefix[i-1],suffix[i+1]);
        ans=ans*c/__gcd(ans,c);
        
    }
    cout<<ans;


}