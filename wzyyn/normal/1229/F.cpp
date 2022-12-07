#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=35005;
int a[N],l[N],r[N],n,S;
priority_queue<ll,vector<ll>,greater<ll>> L,R;
ll check(int v){
	for (;!L.empty();L.pop());
	for (;!R.empty();R.pop());
	ll dl=-v,dr=v,ans=abs(v);
	For(i,1,n+1) L.push(0),R.push(0);
	For(i,1,n){
		dl+=a[i]-l[i];
		dr+=r[i]-a[i];
		if (i!=n){
			ll posl=L.top()+dl;
			ll posr=R.top()+dr;
			if (posl>=0&&posr>=0)
				L.push(-dl),R.push(-dr);
			else if (posl<0){
				ans+=-posl;
				R.push(-posl-dr);
				L.pop();
				L.push(-dl);
				L.push(-dl);
			}
			else{
				ans+=-posr;
				L.push(-posr-dl);
				R.pop();
				R.push(-dr);
				R.push(-dr);
			}
		}
		ll posl=L.top()+dl;
		ll posr=R.top()+dr;
		assert(-posl<=posr);
	}
	dl+=v; dr-=v;
	ll posl=L.top()+dl;
	ll posr=R.top()+dr;
	if (posl>=0&&posr>=0) return ans;
	if (posl<0){
		ll pre=posl;
		for (int tms=1;;++tms){
			L.pop();
			ll now=L.top()+dl;
			if (now>=0) return ans+(-pre)*tms;
			ans+=(now-pre)*tms; pre=now;
		}
	}
	else{
		ll pre=posr;
		for (int tms=1;;++tms){
			R.pop();
			ll now=R.top()+dr;
			if (now>=0) return ans+(-pre)*tms;
			ans+=(now-pre)*tms; pre=now;
		}
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d%d",&a[i],&l[i],&r[i]);
	For(i,1,n) S+=a[i];
	int l=-S,r=S;
	ll ans=1ll<<60;
	while (r-l+1>=4){
		int mid=(2ll*S+l+r)/2-S;
		ll v1=check(mid),v2=check(mid+1);
		ans=min(ans,min(v1,v2));
		if (v1<v2) r=mid;
		else l=mid+1;
	}
	For(i,l,r) ans=min(ans,check(i));
	printf("%lld\n",ans);
}