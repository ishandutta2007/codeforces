#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define NDEBUG
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,K,Q,a[N],b[N],c[N];
pair<int,int[1<<14]>A[1000];
int mod(int k1,int k2){
	k1%=k2;
	if(k1<=0)k1+=k2;
	return k1;
}
namespace sb1{
	void sol(){
		int res=0;
		int bad=0;
		auto calc=[&](int i,int x){
			int s=0;
			for(int j=i;j<=n;j+=K){
				s^=c[j];
				if(s==0)res+=x;
			}
			if(s!=0)bad+=x;
		};
		rep(i,1,K){
			calc(i,1);
		}
		auto mdf=[&](int k1,int k2){
			if(k1>n)return;
			calc(mod(k1,K),-1);
			c[k1]^=k2;
			calc(mod(k1,K),1);
		};
		rep(i,1,Q+1){
			pt(bad?-1:n-res,'\n');
			if(i==Q+1)break;
			int c;while(!islower(c=getchar()));
			int k1,k2;rd(k1),rd(k2);
			if(c=='a'){
				mdf(k1,a[k1]^k2);
				mdf(k1+1,a[k1]^k2);
				a[k1]=k2;
			}else{
				mdf(k1,b[k1]^k2);
				mdf(k1+1,b[k1]^k2);
				b[k1]=k2;
			}
		}
	}
}
namespace sb2{
	int B,bad,res;
	//int num;
	int bel(int x){
		if(K==1)return (x-1)/B+1;
		else return ((x-1)/K/B)*K+(x-1)%K+1;
	}
	int getv(int x){
		return c[x]^A[bel(x)].fi;
	}
	void calc(int i,int x){
		int cur=bel(i);
		int j;
		for(j=i;j<=n&&bel(j)==cur;j+=K){
			//++num;
			res+=x*(getv(j)==0);
		}
		for(;j<=n;j+=K*B){
			//++num;
			res+=x*A[bel(j)].se[A[bel(j)].fi];
		}
		int pos=i+((n-i)/K*K);
		bad+=x*(getv(pos)!=0);
	}
	void mdf(int k1,int k2){
		if(k1>n)return;
		if(K!=1)calc(mod(k1,K),-1);
		else bad=res=0;
		int cur=bel(k1);
		int i;
		for(i=k1;i<=n&&bel(i)==cur;i+=K){
			//++num;
			--A[cur].se[c[i]];
			++A[cur].se[c[i]^=k2];
		}
		for(;i<=n;i+=K*B){
			//++num;
			A[bel(i)].fi^=k2;
		}
		calc(mod(k1,K),1);
	};
	void sol(){
		rep(i,1,n)if(i>=K)c[i]^=c[i-K];
		//int B=max(100,(int)sqrt(1LL*n/K));
		B=sqrt(n)/2;
		if(K==1)B=450;
		/*rep(i,1,n){
			if(i<=10000)printf("bel(%d)=%d\n",i,bel(i));
		}*/
		int tt=0;
		rep(i,1,n){
			++A[bel(i)].se[c[i]];
		}
		cerr<<"tt="<<tt<<endl;
		rep(i,1,K){
			calc(i,1);
		}
		//num=0;
		rep(i,1,Q+1){
#ifdef xay5421
			if(i%1000==0)cerr<<i<<" "<<num<<endl;
#else
			pt(bad?-1:n-res,'\n');
#endif
			if(i==Q+1)break;
			int c;while(!islower(c=getchar()));
			int k1,k2;rd(k1),rd(k2);
			if(c=='a'){
				mdf(k1,a[k1]^k2);
				mdf(k1+1,a[k1]^k2);
				a[k1]=k2;
			}else{
				mdf(k1,b[k1]^k2);
				mdf(k1+1,b[k1]^k2);
				b[k1]=k2;
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(K),rd(Q);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	++n;
	rep(i,1,n)c[i]=a[i-1]^a[i]^b[i-1]^b[i];
	if(K*K>n){
		sb1::sol();
	}else{
		sb2::sol();
	}
	return 0;
}