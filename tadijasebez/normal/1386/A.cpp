#include <bits/stdc++.h>
using namespace std;
#define ll long long
int Dye(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	int ans;
	scanf("%i",&ans);
	return ans;
}
ll SolveFrom(ll x,ll n){
	ll top=n-1,bot=1,mid,ans=n,f=1;
	Dye(x);
	while(top>=bot){
		mid=top+bot>>1;
		int tmp=Dye(x=x+mid*f);
		if(tmp)ans=mid,top=mid-1;
		else bot=mid+1;
		f=-f;
	}
	return ans;
}
ll GetStart(ll n){
	ll o=1;
	vector<ll> v;
	while(o<n){
		v.push_back((o+n-1)>>1);
		o=v.back()+1;
	}
	ll sum=0;
	for(int i=0;i<v.size();i++)sum+=v[i]*((i&1)?1:-1);
	if(v.size()&1)return sum+n;
	else return sum+1;
}
void Solve(){
	ll n;
	scanf("%lld",&n);
	printf("= %lld\n",SolveFrom(GetStart(n),n));
	fflush(stdout);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--)Solve();
	return 0;
}