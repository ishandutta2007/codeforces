#include<bits/stdc++.h>

using namespace std;

int main()
{
    int hh,mm,h,d,c,n;
    cin>>hh>>mm>>h>>d>>c>>n;
    int t0=hh*60+mm,t=20*60;
    double ans1=ceil(h*1.0/n)*c;
    double ans2=ceil((h+(max(t0,t)-t0)*d)*1.0/n)*c*0.8;
    cout<<fixed<<setprecision(10)<<min(ans1,ans2);
}