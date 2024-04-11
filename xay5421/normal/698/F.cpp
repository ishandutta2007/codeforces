// author: xay5421
// created: Mon Oct 11 08:56:55 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
using ULL=unsigned long long;
const int N=1000005;
int n,a[N],p[N],mind[N],miu[N],trans[N];
bool ban[N];
map<int,int>SS;
void sieve(){
	ban[0]=ban[1]=1,miu[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++p[0]]=i;
			miu[i]=-1;
			mind[i]=i;
		}
		for(int j=1;j<=p[0]&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			mind[i*p[j]]=p[j];
			if(i%p[j]==0)break;
			miu[i*p[j]]=-miu[i];
		}
	}
	rep(i,1,N-1){
		int x=i;
		trans[i]=1;
		while(x>1){
			int t=mind[x];
			while(x%t==0)x/=t;
			trans[i]*=t;
		}
	}
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
ULL key[N],key_[N];
int main(){
	sieve();
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(a[i]==0)a[i]=-1;
	vector<int>lstv={-1};
	ULL lstkey=0;
	for(int i=1;i<=p[0]&&p[i]<=n;++i){
		vector<int>v;
		int x=n/p[i];
		while(x>0){
			v.pb(x);
			x/=p[i];
		}
		if(v==lstv){
			key[p[i]]=lstkey;
		}else{
			key[p[i]]=lstkey=rng();
			lstv=v;
		}
	}
	{
		vector<int>v={1};
		if(v==lstv){
			key[1]=lstkey;
		}else{
			key[1]=lstkey=rng();
			lstv=v;
		}
	}
	memcpy(key_,key,sizeof(key_));
	bool flg1=0;
	rep(i,1,n){
		if(a[i]!=-1){
			// !! i==1 || a[i]==1
			/*if(i!=1&&a[i]!=1&&trans[i]!=trans[a[i]]){
				puts("0"),exit(0);
			}*/
			//D("!\n");
			ULL tmp=rng();
			if(i==1){
				key[1]^=tmp;
			}else{
				int x=i;
				while(x>1){
					int t=mind[x];
					while(x%t==0)x/=t;
					key[t]^=tmp;
				}
			}
			if(a[i]==1){
				key_[1]^=tmp;
			}else{
				int y=a[i];
				while(y>1){
					int t=mind[y];
					while(y%t==0)y/=t;
					key_[t]^=tmp;
				}
			}
		}else{
			++SS[trans[i]];
		}
	}
	int ans=1;
	for(auto x:SS)rep(_,1,x.second)ans=mu(ans,_);
	vector<ULL>v1={key[1]},v2={key_[1]};
	for(int i=1;i<=p[0]&&p[i]<=n;++i)v1.pb(key[p[i]]),v2.pb(key_[p[i]]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1!=v2)puts("0"),exit(0);
	for(int i=0,j;i<SZ(v1);i=j){
		j=i+1;
		while(j<SZ(v1)&&v1[i]==v1[j])++j;
		rep(k,1,j-i)ans=mu(ans,k);
	}
	printf("%d\n",ans);
	return 0;
}