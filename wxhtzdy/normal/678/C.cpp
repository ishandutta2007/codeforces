#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    long long i=n/a,j=n/b;
    if(p>q)j-=n/((a*b)/__gcd(a,b));
    else i-=n/((a*b)/__gcd(a,b));
    long long sol=i*p+j*q;
    cout<<sol;
}