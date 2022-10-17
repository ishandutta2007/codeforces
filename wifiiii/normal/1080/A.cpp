#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    long long ans = 2*n/k+5*n/k+8*n/k;
    if(2*n%k)ans++;
    if(5*n%k)ans++;
    if(8*n%k)ans++;
    cout << ans << endl;
}