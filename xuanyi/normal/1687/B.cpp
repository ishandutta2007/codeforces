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

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>l(m+1),id(m+1);
	rep(i,1,m){
		printf("? ");
		rep(j,1,m)printf("%d",i==j?1:0);
		puts("");
		fflush(stdout);
		scanf("%d",&l[i]);
		id[i]=i;
	}
	sort(id.begin()+1,id.end(),[&](int lhs,int rhs){return l[lhs]<l[rhs];});
	vector<int>cur(m+1);
	int ret=0;
	rep(i,1,m){
		cur[id[i]]=1;
		printf("? ");
		rep(j,1,m)printf("%d",cur[j]);
		puts("");
		fflush(stdout);
		int tmp;
		scanf("%d",&tmp);
		if(tmp==ret+l[id[i]])ret=tmp;
		else cur[id[i]]=0;
	}
	printf("! %d\n",ret);
	return 0;
}