#include <bits/stdc++.h>
using namespace std;
long long ans=0;
void gett(int x,int n)
{
    if(x>n) return;
    ans++;
    gett(10*x,n);
    gett(10*x+1,n);
}
int main()
{
    long long n;
    cin>>n;
    gett(1,n);
    cout<<ans<<endl;
    return 0;
}