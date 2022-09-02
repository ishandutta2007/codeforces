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
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int T,n;
deque<int>vec[N];
char s[N],t[N],ss[N];
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}tr;
void sol(){
	rd(n);
	scanf("%s%s",s+1,t+1);
	if(strcmp(s+1,t+1)<0){
		puts("0");
		return;
	}
	{
		rep(i,1,n)ss[i]=s[i];
		sort(ss+1,ss+1+n);
		if(strcmp(ss+1,t+1)>=0){
			puts("-1");
			return;
		}
	}
	rep(i,0,25)vec[i].clear();
	rep(i,1,n){
		vec[s[i]-'a'].pb(i);
	}
	rep(i,1,n){
		tr.t[i]=1;
	}
	rep(i,1,n){
		if(i+(i&-i)<=n){
			tr.t[i+(i&-i)]+=tr.t[i];
		}
	}
	int i=1;
	while(i<=n&&s[i]==t[i]){
		vec[s[i]-'a'].pop_front();
		++i;
	}
	rep(j,1,i-2)if(s[j]>s[j+1]){
		puts("1");
		return;
	}
	auto erase=[&](int x){
		//D("erase %d\n",x);
		tr.upd(1,1);
		tr.upd(x,-1);
	};
	auto real=[&](int x){
		//D("real %d=%d\n",x,tr.qry(x));
		return tr.qry(x);
	};
	auto work=[&](int x){
		erase(vec[x][0]);
		vec[x].pop_front();
	};
	long long ans=5e18;
	long long base=0;
	if(i>1){
		rep(j,0,s[i-1]-'a'-1){
			if(!vec[j].empty()){
				ans=min<long long>(ans,real(vec[j][0])-(i-1));
			}
		}
	}
	while(i<=n){
		rep(j,0,t[i]-'a'-1){
			if(!vec[j].empty()){
				ans=min<long long>(ans,base+real(vec[j][0])-i);
			}
		}
		if(vec[t[i]-'a'].empty()){
			break;
		}
		base+=real(vec[t[i]-'a'][0])-i;
		work(t[i]-'a');
		i+=1;
	}
	printf("%lld\n",ans);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		sol();
	}
	return 0;
}