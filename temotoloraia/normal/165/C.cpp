#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=1e6+5;
const ll INF=1e17;
ll k,n,a[N],st[N],en[N],np;
ll ans;
string s;
ll f (ll x){
	return (x-1)*x/2;
}
int main(){
	cin>>k>>s;
	n=s.size();
	s="#"+s;
	for (int i=1;i<=n;i++)a[i]=a[i-1]+s[i]-'0';
	np=a[n];
	st[0]=0;
	for (int i=1;i<=n;i++)
	if (a[i]>a[i-1]){
		st[a[i]]=i;
		en[a[i-1]]=i-1;
	}
	en[np]=n;
	if (k>0){
	for (int i=0;i+k<=np;i++)
	ans+=(en[i]-st[i]+1)*(en[i+k]-st[i+k]+1);
	cout<<ans<<endl;
    return 0;
	}
	for (int i=0;i<=np;i++)ans+=f(en[i]-st[i]+1);
	cout<<ans<<endl;
    return 0;
}