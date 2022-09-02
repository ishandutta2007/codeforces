#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=100005;
int n,s1,s2,x[N];
set<int>S1,S2;
bool check(int mid){
	S1={s1};
	S2={s2};
	rep(i,1,n){
		int f1=!S1.empty(),f2=!S2.empty();
		
		{
			int l=x[i]-mid,r=x[i]+mid;
			while(!S1.empty()&&*S1.begin()<l)S1.erase(S1.begin());
			while(!S1.empty()&&*--S1.end()>r)S1.erase(--S1.end());
			if(i>1){
				if(f2&&abs(x[i]-x[i-1])<=mid){
					S1.insert(x[i-1]);
				}
			}
		}
		
		{
			int l=x[i]-mid,r=x[i]+mid;
			while(!S2.empty()&&*S2.begin()<l)S2.erase(S2.begin());
			while(!S2.empty()&&*--S2.end()>r)S2.erase(--S2.end());
			if(i>1){
				if(f1&&abs(x[i]-x[i-1])<=mid){
					S2.insert(x[i-1]);
				}
			}
		}
		if(S1.empty()&&S2.empty())return 0;
	}
	return 1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(s1),rd(s2);
	rep(i,1,n)rd(x[i]);
	int l=abs(s1-s2),r=1000000000,ret=r;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ret=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",ret);
	return 0;
}