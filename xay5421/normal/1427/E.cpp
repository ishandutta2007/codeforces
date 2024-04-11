#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
//mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(20050403);
int x,n=0;
LL v[100005],b[65];
set<LL>S;
vector<tuple<int,char,int> >ans;
void chk(LL num){
	//D("chk %lld\n",num);
	int top=SZ(ans);
	for(int i=60;i>=0;--i){
		if(num>>i&1){
			if(!b[i]){
				//while(SZ(ans)>top)S.erase(get<0>(ans.back())^get<2>(ans.back())),--n,ans.pop_back();
				return;
			}
			if(!S.count(num^1^b[i])){
				ans.EB(num^1,'^',b[i]);
				S.insert(num^1^b[i]);
				v[++n]=num^1^b[i];
			}
			num^=b[i];
		}
	}
	pt(SZ(ans),'\n');
	rep(i,0,SZ(ans)-1)printf("%lld %c %lld\n",get<0>(ans[i]),get<1>(ans[i]),get<2>(ans[i]));
	exit(0);
}
void ins(LL num){
	int top=SZ(ans);
	for(int i=60;i>=0;--i){
		if(num>>i&1){
			if(!b[i]){
				b[i]=num;
				return;
			}
			if(!S.count(num^b[i])){
				ans.EB(num,'^',b[i]);
				S.insert(num^b[i]);
				v[n++]=num^b[i];
			}
			num^=b[i];
		}
	}
	//while(SZ(ans)>top)S.erase(get<0>(ans.back())^get<2>(ans.back())),--n,ans.pop_back();
}
bool push(LL w,tuple<int,char,int>t){
	if(w>=1e18)return 0;
	if(S.count(w))return 0;
	ans.PB(t);
	S.insert(w);
	chk(w^1);
	ins(w);
	v[n++]=w;
	return 1;
}
void push1(LL a,LL b){
	push(a+b,make_tuple(a,'+',b));
}
void push2(LL a,LL b){
	push(a^b,make_tuple(a,'^',b));
}
signed main(){
	rd(x);
	v[n++]=x;
	S.insert(x);
	ins(x);
	rep(i,1,100){
		v[i]=v[i-1]+x;
		ans.EB(x,'+',v[i-1]);
		S.insert(v[i]);
		ins(v[i]);
	}
	ans.EB(x,'^',x);
	while(1){
		auto get=[](){
			LL x=0;
			for(int i=60;i>=0;--i)if(b[i]&&(rng()&1)){
				ans.EB(x,'^',b[i]);
				x^=b[i];
				S.insert(x);
			}
			return x;
		};
		LL a=get(),b=get();
		push1(a,b);
		push2(a,b);
		//rep(i,0,60)if(::b[i])assert(S.count(::b[i]));
	}
	return 0;
}