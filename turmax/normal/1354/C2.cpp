#include <bits/stdc++.h>

using namespace std;
#define int long long
double PI=3.14159265358979;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15)<<"";
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    n*=2;
    double alpha=2.0*PI/n;
    cout<<cos(alpha/4.0)/(sin(alpha/2.0))<<endl;
    }
    return 0;
}