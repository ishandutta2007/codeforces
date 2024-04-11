#include<bits/stdc++.h>
#define ll long long

std::mt19937 rng(time(0));

int I,J,K;

int _;
inline ll qry(int l,int r){
//	if(++_>40)
//		assert(0);
	printf("? %d %d\n",l,r);
	fflush(stdout);
	static ll res=0;
//	res=0;
//	int L=std::max(l,I),R=std::min(r,J-1);
//	if(L<R)
//		res+=1ll*(R-L)*(R-L+1)/2;
//	L=std::max(l,J),R=std::min(r,K);
//	if(L<R)
//		res+=1ll*(R-L)*(R-L+1)/2;
//	printf("%lld\n",res);
	scanf("%lld",&res);
	return res;
}

int T;

int n;

inline int sol(ll x){
	ll L=1,R=n,res=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(1ll*mid*(mid-1)/2<=x)
			res=mid,L=mid+1;
		else
			R=mid-1;
	}
	return 1ll*res*(res-1)/2==x?res:-1;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
//		scanf("%d%d%d",&I,&J,&K);
//		n=10;
//		I=rng()%n+1,J=rng()%n+1,K=rng()%n+1;
//		while(!(J-I>1&&J<K))
//			I=rng()%n+1,J=rng()%n+1,K=rng()%n+1;
//		_=0;
//		printf("%d\n%d %d %d\n",n,I,J,K);
		int L=1,R=n;
		ll s=qry(1,n);
		while(L<=R){
			int mid=(L+R)>>1;
			ll x=qry(L,mid);
			if(x&&x!=s){
				x=qry(1,mid);
				ll y=qry(mid+1,n),z=s-x-y;
				int i=sol(x),j=sol(y);
				std::vector<std::tuple<int,int,int>> p;
				if((~i)&&z%i==0){
					int k=z/i;
					int l=sol(y-1ll*k*(k-1)/2);
					if(~l)
						p.emplace_back(mid-i+1,mid+k+1,mid+k+l);
				}
				if((~j)&&z%j==0){
					int k=z/j;
					int l=sol(x-1ll*k*(k-1)/2);
					if(~l)
						p.emplace_back(mid-k-l+1,mid-k+1,mid+j);
				}
				bool ff=0,flg=0;
				for(auto [a,b,c]:p)
					if(flg||(a>=1&&c<=n&&a+1<b&&b<c&&qry(a,b-1)==1ll*(b-a)*(b-a-1)/2&&qry(b,c)==1ll*(c-b+1)*(c-b)/2)){
						printf("! %d %d %d\n",a,b,c);
						ff=1;
//						assert(a==I&&b==J&&c==K);
						break;
					}
					else
						flg=1;
				std::fflush(stdout);
				assert(ff);
				break;
			}
			if(!x)
				L=mid;
			else
				R=mid;
		}
	}
}