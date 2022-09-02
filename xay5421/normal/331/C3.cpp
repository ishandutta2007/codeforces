//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
std::map<pii,pii>mmp;
int n;
pii go(int v,int mx){
	if(v==0)return pii(0,0);
	if(v<10){
		if(v<mx)return pii(1,mx-v);
		else return pii(1,0);
	}
	pii state=pii(v,mx);
	if(mmp.count(state))return mmp[state];
	ll step=1;
	while(step<=v/10)step*=10;
	pii ans=pii(0,0);
	while(1){
		int num=v/step;
		int newmx=mx;
		if(num>newmx)newmx=num;
		pii cur=go(v%step,newmx);
		ans.first+=cur.first;
		v=v/step*step;
		if(cur.second>0)v-=cur.second;
		else{
			v-=newmx;
			if(newmx>0)++ans.first;
		}
		if(num==0)break;
	}
	ans.second=-v;
	return mmp[state]=ans;
	return ans;
}
signed main(){
	rd(n);
	pii res=go(n,0);
	pt(res.first,'\n');
	return 0;
}