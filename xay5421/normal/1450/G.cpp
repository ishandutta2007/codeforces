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
const int N=5005;
int n,a,b,ll[26],rr[26],cnt[26];
char s[N];
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	rep(i,1,n){
		if(!ll[s[i]-'a']){
			ll[s[i]-'a']=i;
		}
		rr[s[i]-'a']=i;
		++cnt[s[i]-'a'];
	}
	vector<int>id;
	rep(i,0,25)if(rr[i]){
		id.pb(i);
	}
	if(SZ(id)==1){
		printf("1 %c\n",id[0]+'a');
		exit(0);
	}
	sort(id.begin(),id.end(),[&](int lhs,int rhs){return ll[lhs]<ll[rhs];});
	vector<int>dp(1<<SZ(id));
	rep(i,0,SZ(id)-1){
		if(a*(rr[id[i]]-ll[id[i]]+1)<=b*cnt[id[i]]){
			dp[1<<i]=1;
		}
	}
	rep(i,1,(1<<SZ(id))-1){
		if(!(i&(i-1)))continue;
		int l=0,r=0,tt=0;
		int mask=0;
		rep(j,0,SZ(id)-1)if(i>>j&1){
			if(!l)l=ll[id[j]];
			r=max(r,rr[id[j]]);
			tt+=cnt[id[j]];
			mask|=1<<j;
			if(dp[mask]&&dp[i^mask]){
				dp[i]=1;
				break;
			}
		}
		if(!dp[i]&&a*(r-l+1)<=b*tt){
			rep(j,0,SZ(id)-1)if(i>>j&1){
				dp[i]|=dp[i^(1<<j)];
			}
		}
	}
	// DD(dp);
	vector<char>v;
	rep(i,0,SZ(id)-1)if(dp[(1<<SZ(id))-1-(1<<i)])v.pb(id[i]+'a');
	printf("%d ",SZ(v));
	sort(v.begin(),v.end());
	for(auto&x:v)printf("%c ",x);
	puts("");
	return 0;
}