#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,t[N],ans[N];
set<int>S,T;
signed main(){
	rd(n);
	char o[5];
	rep(i,1,n*2){
		scanf("%s",o);
		if(o[0]=='+'){
			S.insert(i);
		}else{
			int x;
			rd(x);
			t[x]=i;
			T.insert(i);
		}
	}
	rep(i,1,n){
		auto it=S.upper_bound(t[i]);
		if(it==S.begin()){
			puts("NO");
			exit(0);
		}
		--it;
		ans[*it]=i;
		auto p=T.lower_bound(t[i]);
		if(p!=T.begin()){
			if(*prev(p)>*it){
				puts("NO");
				exit(0);
			}
		}
		S.erase(it);
		T.erase(p);
	}
	puts("YES");
	rep(i,1,n*2)if(ans[i])pt(ans[i],' ');
	return 0;
}