#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,m,s,ans;
	cin>>n>>m>>s;
	ll x=n%s;
    ll y=m%s;
    ll z=n/s;
    ll w=m/s;
    if(x==0) x=s;
    else z++;
    if(y==0) y=s;
    else w++;
    ans=x*y*z*w;
    cout<<ans<<endl;
	return 0;
}