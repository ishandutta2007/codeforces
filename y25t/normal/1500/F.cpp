#include<bits/stdc++.h>
#define N 1000005
#define ll long long

int n;
ll a[N];

ll d[N];

ll L,R;
std::multiset<ll> S;
int k=1;
ll b;
inline ll f(ll x){
	return k*x+b;
}
inline ll fi(ll x){
	return k*(x-b);
}
ll Lo[N],Ro[N],L_[N],R_[N],k_[N],b_[N];
std::vector<ll> V[N];
std::multiset<ll> T[N];
#define Lo Lo[i]
#define Ro Ro[i]
#define L_ L_[i]
#define R_ R_[i]
#define k_ k_[i]
#define b_ b_[i]
#define V V[i]
#define T T[i]

ll h[N];

int main(){
	scanf("%d%lld",&n,&R);
	for(int i=2;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++){
		if(i==n){
			d[n]=L<=R?L:f(*S.begin());
			break;
		}
		Lo=L,Ro=R;
		R=std::min(R,a[i]);
		if(L>R)
			L=0,R=-1;
		while(S.size()&&f(*S.begin())>a[i])
			V.push_back(*S.begin()),S.erase(S.begin());
		while(S.size()&&f(*S.rbegin())>a[i])
			V.push_back(*S.rbegin()),S.erase(std::prev(S.end()));
		if(L>R&&!S.size())
			puts("NO"),exit(0);
		L_=L,R_=R,k_=k,b_=b;
		if(S.count(fi(a[i]))||(L<=a[i]&&a[i]<=R)){
			L=0,R=a[i];
			std::swap(S,T);
		}
		else{
			k=-k,b=a[i]-b;
			if(L<=R)
				L=a[i]-L,R=a[i]-R,std::swap(L,R);
		}
		S.insert(fi(a[i]));
	}
	for(int i=n-1;i>=2;i--){
		S.erase(S.find(fi(a[i])));
		if(T.size())
			std::swap(S,T);
		L=L_,R=R_,k=k_,b=b_;
		ll res;
		if(S.count(fi(a[i]))||(L<=a[i]&&a[i]<=R))
			res=a[i];
		else if(d[i+1]==a[i])
			res=L<=R?L:f(*S.begin());
		else
			res=a[i]-d[i+1];
		for(auto x:V)
			S.insert(x);
		L=Lo,R=Ro;
		d[i]=res;
	}
	for(int i=2;i<=n;i++){
		h[i]=h[i-1]+d[i];
		if(i>2&&std::max(h[i-2],std::max(h[i-1],h[i]))
				-std::min(h[i-2],std::min(h[i-1],h[i]))!=a[i-1])
			h[i]=h[i-1]-d[i];
	}
	ll tmp=*std::min_element(h+1,h+n+1);
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%lld ",h[i]-tmp);
	puts("");
}