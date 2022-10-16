#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    
    long long mod = 1000000007;
    long long n,m; 
    cin>>n>>m;
    long long x=sqrt(n);
    long long sum=(m%mod)*(n%mod);
    sum%=mod;
    long long a=0;
    long long b;
    if(x>m) x=m;
    for(long long i=1;i<=x;i++)
    {
        a+=(((long long)(n/(i)))*(i))%mod;
        a%=mod;
        b=((long long)(n/(i)))%mod;
    }
    bool l=true;
    for(long long i=b-1;i>=1;i--)
    {
        long long lower = (n/(i+1));
        long long upper = (n/i);
        if(lower>m) {lower=m;l=false;}
        if(upper>m) {upper=m;l=false;}
        upper%=mod;
        lower%=mod;
        long long g=(upper*(((mod+1)/2)))%mod;
        long long h=(lower*(((mod+1)/2)))%mod;
        long long p=((((g)%mod)*((upper+1))%mod)%mod);
        long long q=((((h)%mod)*((lower+1))%mod)%mod);
        long long num= (p-q);
        a+=(((num))*(i))%mod;
        a%=mod;
 
        if(l==false) break;
    }
    cout<<(sum-a+mod)%mod<<"\n";
}