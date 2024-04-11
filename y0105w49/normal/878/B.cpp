// ayy
// ' lamo
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const ld tau=2*acosl(-1);
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;







const int N=100<<10;
int a[N],n,k,m;


int ct[N*5],b[N*5];
int solve(const vector<int> &v) {
	int i=1;
	for(int x:v) {
		b[i]=x;
		if(i>1 && b[i]==b[i-1]) ct[i]=ct[i-1]+1;
		else ct[i]=1;
		if(ct[i]==k) i-=k;
		++i;
	}
	return i-1;
}

int32_t main() {
	scanf("%d%d%d",&n,&k,&m);
	int i=1;
	for(int j=1;j<=n;j++) {
		scanf("%d",a+i);
		if(i>1 && a[i]==a[i-1]) ct[i]=ct[i-1]+1;
		else ct[i]=1;
		if(ct[i]==k) i-=k;
		++i;
	}

	int L=1,R=i-1;
	// cerr<<L<<" "<<R<<endl;
	vector<int> ww,vv;
	for(;L<=R && a[L]==a[R];) {
		int tr=0;
		for(int i=R;i>=L;i--) {
			if(tr>=k) break;
			if(a[i]==a[R]) ++tr;
			else break;
		}
		int st=0;
		for(int i=L;i<=R;i++) {
			if(st>=k) break;
			if(a[i]==a[L]) ++st;
			else break;
		}
		if(st+tr>=R-L+1) {
			int err=int(1LL*(R-L+1)*m%k);
			if(err) for(;err<k && vv.size() && vv.back()==a[L];) vv.pop_back(), ++err;
			if(err) for(;err<k && ww.size() && ww.back()==a[R];) ww.pop_back(), ++err;
			err%=k;
			if(err) printf("%d\n",solve(vv)+solve(ww)+err);
			else {
				reverse(ww.begin(),ww.end());
				for(int x:ww) vv.pb(x);
				printf("%d\n",solve(vv));
			}
			return 0;
		}
		if(st+tr>=k) {
			tr=min(tr,k-st);
			for(;st;) vv.pb(a[L++]),--st;
			for(;tr;) ww.pb(a[R--]),--tr;
			assert(L<=R);
		} else break;
	}
	ll Z=1LL*m*(R-L+1);
	assert(solve(vv)==(int)vv.size());
	assert(solve(ww)==(int)ww.size());
	if(!Z) {
		reverse(ww.begin(),ww.end());
		for(int x:ww) vv.pb(x);
		printf("%d\n",solve(vv));
	} else {
		printf("%lld\n",Z+solve(vv)+solve(ww));
	}
}