// author: xay5421
// created: Sun Aug 29 22:41:26 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=100005;
int T,n,a[N],b[N];
struct BIT{
	int t[N];
	void clear(){rep(i,1,n)t[i]=0;}
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
LL work(vector<int>v){
	rep(i,1,n){
		b[i]=v[a[i]&1];
		v[a[i]&1]+=2;
	}
	t.clear();
	LL res=0;
	per(i,n,1){
		res+=t.qry(b[i]);
		t.upd(b[i],1);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		int tt[2]={0,0};
		rd(n);
		rep(i,1,n){
			rd(a[i]);
			++tt[a[i]&1];
		}
		if(n%2==0){
			if(tt[0]!=tt[1]){puts("-1");continue;}
		}else{
			if(abs(tt[0]-tt[1])!=1){puts("-1");continue;}
		}
		LL ans;
		if(n%2==0){
			ans=min(work({2,1}),work({1,2}));
		}else{
			ans=tt[0]>tt[1]?work({1,2}):work({2,1});
		}
		pt(ans,'\n');
	}
	return 0;
}