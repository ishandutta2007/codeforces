#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) {cin>>a[i];a[i]*=inv(100);a[i]%=p;}
    int p1=1;for(int i=0;i<n;++i) {p1*=a[i];p1%=p;}
    int ans1=1;int p2=1;for(int i=0;i<n;++i) {ans1+=((p2*a[i])%p);ans1%=p;p2*=a[i];p2%=p;}
    int res=ans1;res%=p;res*=inv(p1);res%=p;
    cout<<(res%p+p-1)%p;
    return 0;
}