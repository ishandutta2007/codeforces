#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
         int n;cin>>n;string s;cin>>s;
         int a[2*n+1];a[0]=0;for(int i=0;i<2*n;++i) {a[i+1]=a[i]; if(s[i]=='(') a[i+1]++; else a[i+1]--;}
         int l1=(-1);int pos1=0;vector<pair<int,int> > res;
         int ma=0;int mi1=1e9;int ma1=(-1);for(int i=0;i<=2*n;++i) {if(a[i]<0) {mi1=min(mi1,i);ma1=max(ma1,i);}}
         if(ma1==(-1)) {cout<<0<<'\n';continue;}
         int pos3=0;
         for(int i=1;i<mi1;++i) {if(a[i]>a[pos3]) {pos3=i;}}
         int pos4=2*n;
         for(int i=2*n-1;i>ma1;--i) {if(a[i]>a[pos4]) {pos4=i;}}
         int pos5=pos3;
         for(int i=pos3;i<=pos4;++i) {if(a[i]>a[pos5]) {pos5=i;}}
         if(a[pos5]<=a[pos3]+a[pos4])
         {
             cout<<1<<'\n';
             cout<<pos3+1<<' '<<pos4<<'\n';continue;
         }
         for(int i=0;i<=2*n;++i) {if(a[i]>a[pos5]) {pos5=i;}}
         cout<<2<<'\n';
         cout<<1<<' '<<pos5<<'\n';
         cout<<pos5+1<<' '<<2*n<<'\n';
    }
    return 0;
}