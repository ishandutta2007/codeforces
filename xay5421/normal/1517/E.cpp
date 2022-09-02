// author: xay5421
// created: Fri Apr 23 23:20:38 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int T,n,a[N],top;
LL num[N];
LL s1[N],s2[N],s3[N];
struct BIT{
	int t[N];
	void upd1(int k1,int k2){
		for(int i=k1;i<=top;i+=i&-i)t[i]+=k2;
	}
	int qry1(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	void upd2(int k1,int k2){
		for(int i=k1;i;i&=i-1)t[i]+=k2;
	}
	int qry2(int k1){
		int k2=0;
		for(int i=k1;i<=top;i+=i&-i)k2+=t[i];
		return k2;
	}
	void clear(){
		memset(t,0,(top+1)*sizeof(t[0]));
	}
}t[2];
void ls(){
	sort(num+1,num+1+top);
	top=unique(num+1,num+1+top)-num-1;
}
void clear(){
	t[0].clear(),t[1].clear();
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		int ans=1;
		{
			// CCCCC PCPCPCPCPC PPPPP
			clear();
			rep(i,1,n)s2[i]=a[i]-s2[i-1],s1[i]=s1[i-1]+a[i];
			s3[n+1]=0;
			per(i,n,0)s3[i]=s3[i+1]+a[i];
			rep(i,1,n-1){
				// PPPPP CCCC
				if(s1[i]>s3[i+1])uad(ans,1);
			}
			top=0;
			rep(i,1,n-1)num[++top]=s3[i+1]-s2[i];
			ls();
			per(i,n-1,1){
				int p=lower_bound(num+1,num+1+top,s3[i+1]-s2[i])-num;
				t[i&1].upd2(p,1);
				int pos=upper_bound(num+1,num+1+top,s1[i]-s2[i])-num;
				uad(ans,t[i&1].qry2(pos));
			}
		}
		{
			// PCCC PCPCPCPC PPP
			clear();
			rep(i,1,n)s2[i]=a[i]-s2[i-1],s1[i]=s1[i-1]+(i==1?-a[i]:a[i]);
			s3[n+1]=0;
			per(i,n,0)s3[i]=s3[i+1]+a[i];
			top=0;
			rep(i,1,n-1)num[++top]=s3[i+1]-s2[i];
			ls();
			per(i,n-1,2){
				int p=lower_bound(num+1,num+1+top,s3[i+1]-s2[i])-num;
				t[i&1].upd2(p,1);
				int pos=upper_bound(num+1,num+1+top,s1[i]-s2[i])-num;
				uad(ans,t[i&1].qry2(pos));
			}
		}
		{
			// CCCC PCPCPCPC PPPC
			clear();
			rep(i,1,n)s2[i]=a[i]-s2[i-1],s1[i]=s1[i-1]+a[i];
			s3[n+1]=0;
			per(i,n,0)s3[i]=s3[i+1]+(i==n?-a[i]:a[i]);
			top=0;
			rep(i,1,n-2)num[++top]=s3[i+1]-s2[i];
			ls();
			per(i,n-2,1){
				int p=lower_bound(num+1,num+1+top,s3[i+1]-s2[i])-num;
				t[i&1].upd2(p,1);
				int pos=upper_bound(num+1,num+1+top,s1[i]-s2[i])-num;
				uad(ans,t[i&1].qry2(pos));
			}
		}
		{
			clear();
			rep(i,1,n)s2[i]=a[i]-s2[i-1],s1[i]=s1[i-1]+(i==1?-a[i]:a[i]);
			s3[n+1]=0;
			per(i,n,0)s3[i]=s3[i+1]+(i==n?-a[i]:a[i]);
			top=0;
			rep(i,2,n-2)num[++top]=s3[i+1]-s2[i];
			ls();
			per(i,n-2,2){
				int p=lower_bound(num+1,num+1+top,s3[i+1]-s2[i])-num;
				t[i&1].upd2(p,1);
				int pos=upper_bound(num+1,num+1+top,s1[i]-s2[i])-num;
				uad(ans,t[i&1].qry2(pos));
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}