#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int n,m,K,all,a[N],b1[N],b2[N],b3[N];
void push(int*a,int*b,int k,int&w1,int w2){
	copy(b,b+K,b3);
	uad(w1,w2);
	rep(i,0,K-1){
		uad(w1,mu(a[(i+k)%K],b3[i]));
	}
	rep(i,0,K-1){
		uad(a[(i+k)%K],b3[i]);
	}
}
void ps(int*a,int*b,int k,int&w1,int w2){
	copy(b,b+K,b3);
	uad(w1,w2);
	rep(i,0,K-1){
		uad(w1,mu(a[(i+k)%K],b3[(i+all)%K]));
	}
	rep(i,0,K-1){
		uad(a[(i+k)%K],b3[i]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,n)scanf("%d",&a[i]);
	int ans=0;
	{
		int sum=0;
		int w1=0,w2=0;
		rep(i,1,n){
			(sum+=a[i])%=K;
			uad(w1,b1[sum]);
			++b1[sum];
		}
		int l1=sum,l2=0;
		b2[0]=1;
		int m_=m;
		while(m_){
			if(m_&1){
				push(b2,b1,l2,w2,w1);
				(l2+=l1)%=K;
			}
			m_>>=1;
			push(b1,b1,l1,w1,w1);
			(l1+=l1)%=K;
		}
		uad(ans,w2);
		all=1LL*sum*m%K;
	}
	{
		int sum=0;
		int w1=0,w2=0;
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		rep(i,1,n){
			(sum+=a[i])%=K;
			uad(w1,b1[(sum-all+K)%K]);
			++b1[sum];
		}
		int l1=sum,l2=0;
		int m_=m;
		while(m_){
			if(m_&1){
				ps(b2,b1,l2,w2,w1);
				(l2+=l1)%=K;
			}
			m_>>=1;
			ps(b1,b1,l1,w1,w1);
			(l1+=l1)%=K;
		}
		usu(b2[all],1);
		usu(w2,b2[0]);
		uad(ans,w2);
	}
	printf("%d\n",ans);
	return 0;
}