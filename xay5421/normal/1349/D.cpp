#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
int add(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int sub(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mul(int k1,int k2){return 1LL*k1*k2%P;}
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mul(k1,k1))if(k2&1)k3=mul(k3,k1);
	return k3;
}
const int N=300005;
int n,a[N],f[N],sum,co[N][4];
bool pd[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),sum+=a[i];
	f[sum]=0;
	const int invn1=fpow(n-1,P-2),invs=fpow(sum,P-2);
	co[sum][1]=P-1;
	rep(i,0,sum-1){
		if(i==0){
			co[i][0]=0;
			co[i][1]=sub(mul(n-2,invn1),1);
			co[i][2]=invn1;
			co[i][3]=P-1;
		}else{
			int t=mul(sub(sum,i),invs);
			co[i][0]=mul(i,invs);
			co[i][1]=sub(mul(mul(n-2,invn1),t),1);
			co[i][2]=mul(invn1,t);
			co[i][3]=P-1;
		}
	}
	per(i,sum-1,0){
		//D("%d\n",i);
		if(co[i][2]){
			if(co[i+1][1]){
				int num=mul(co[i][2],fpow(co[i+1][1],P-2));
				co[i][3]=sub(co[i][3],mul(co[i+1][3],num));
				assert(co[i+1][2]==0);
				co[i][2]=sub(co[i][2],mul(co[i+1][1],num));
				co[i][1]=sub(co[i][1],mul(co[i+1][0],num));
			}
		}
		if(co[i][0]&&!co[i][1]&&!co[i][2]){
			int I0=fpow(co[i][0],P-2);
			if(i>=1){
				int t=mul(co[i-1][1],I0);
				co[i-1][1]=sub(co[i-1][1],mul(co[i][0],t));
				co[i-1][3]=sub(co[i-1][3],mul(co[i][3],t));
			}
			if(i>=2){
				int t=mul(co[i-2][2],I0);
				co[i-2][2]=sub(co[i-2][2],mul(co[i][0],t));
				co[i-2][3]=sub(co[i-2][3],mul(co[i][3],t));
			}
		}
	}
	pd[sum]=1,f[sum]=0;
	rep(i,0,sum-1){
		if(co[i][0]&&pd[i-1]){
			co[i][3]=sub(co[i][3],mul(f[i-1],co[i][0]));
			co[i][0]=0;
		}
		if(co[i][1]&&pd[i]){
			co[i][3]=sub(co[i][3],mul(f[i],co[i][1]));
			co[i][1]=0;
		}
		if(co[i][2]&&pd[i+1]){
			co[i][3]=sub(co[i][3],mul(f[i],co[i][2]));
			co[i][2]=0;
		}
		assert((co[i][0]>0)+(co[i][1]>0)+(co[i][2]>0)<=1);
		if(co[i][0]){
			pd[i-1]=1,f[i-1]=mul(co[i][3],fpow(co[i][0],P-2));
		}
		if(co[i][1]){
			pd[i]=1,f[i]=mul(co[i][3],fpow(co[i][1],P-2));
		}
		if(co[i][2]){
			pd[i+1]=1,f[i+1]=mul(co[i][3],fpow(co[i][2],P-2));
		}
	}
	int ans=0;
	rep(i,1,n)ans=add(ans,f[a[i]]);
	ans=sub(ans,mul(n-1,f[0]));
	printf("%d\n",mul(ans,fpow(n,P-2)));
	return 0;
}