// author: xay5421
// created: Sat Oct  9 17:08:48 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,a[N];
char s[N];
mt19937 rng(233);
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	scanf("%s",s+1);
	/*n=100;
	set<int>S;
	rep(i,1,n){
		a[i]=rng()%1000+1;
		if(S.count(a[i])){--i;continue;}
		S.insert(a[i]);
	}
	rep(i,1,n)s[i]=rng()&1?'L':'R';*/
	sort(a+1,a+1+n);
	vector<int>num;
	LL dt=0;
	int pos=n+1;
	rep(i,1,n){
		if(i==1||s[i]!=s[i-1]){
			--pos;
		}
	}
	int cur=pos-1;
	int op=1;
	rep(i,1,n){
		if(i==1||s[i]!=s[i-1]){
			if(s[i]=='L'){
				if(i==1)op=1;
				num.pb(-a[pos++]);
			}else{
				if(i==1)op=-1;
				num.pb(a[pos++]);
			}
		}else{
			num.pb(op*a[cur--]);
			op*=-1;
		}
	}
	dt=0;
	cur=0;
	for(auto x:num){
		dt+=x;
		assert(dt!=0);
		if(dt<0)assert(s[++cur]=='L');
		else assert(s[++cur]=='R');
	}
	for(auto x:num)if(x<0)printf("%d L\n",-x);else printf("%d R\n",x);
	return 0;
}