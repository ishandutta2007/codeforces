#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

/*struct SegTree{
	vector<int> mx;
	int n;
	SegTree(){}
	void init(int _n){n=_n;mx.assign(n*2,0);}
	void Set(int i,int f){for(i+=n;i;i>>=1)ckmx(mx[i],f);}
	int Get(int l,int r){
		int ans=0;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
			if(l%2==1)ckmx(ans,mx[l++]);
			if(r%2==0)ckmx(ans,mx[r--]);
		}
		return ans;
	}
}ST[2];*/
int main(){
	int n,k;rd(n,k);
	vector<int> a(n);
	rd(a);
	int top=1e9,bot=1,mid,ans;
	while(top>=bot){
		int mid=top+bot>>1;
		vector<int> b(n);
		for(int i=0;i<n;i++)b[i]=a[i]<=mid;
		int now=0;
		for(int i=0;i<n-(k%2==0);i++){
			if(b[i]){
				now++;
				i++;
			}
		}
		bool ok=0;
		if(now>=(k+1)/2)ok=1;
		now=0;
		for(int i=1;i<n-(k%2==1);i++){
			if(b[i]){
				now++;
				i++;
			}
		}
		if(now>=k/2)ok=1;
		if(ok)ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}