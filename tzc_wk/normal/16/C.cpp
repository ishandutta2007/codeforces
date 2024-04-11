#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm> 
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) {
	return b>0?gcd(b,a%b):a;
}
int main(){
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
    ll GCD=gcd(x,y);
    x/=GCD,y/=GCD;
    ll t1=a/x;
    ll t2=b/y;
    int ANS=min(t1, t2);
    cout<<x*ANS<<" "<<y*ANS<<endl;
	return 0;
}