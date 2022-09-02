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
#define fi first
#define se second
#define EB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,a[N],b[N],st[N],st2[N],top,top2;
vector<pair<int,int> >ans;
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	int ind=n+1;
	per(i,n,1){
		if(!a[i])continue;
		if(a[i]==1){
			b[i]=--ind;
			ans.EB(b[i],i);
			st[++top]=i;
		}else if(a[i]==2){
			if(!top){
				puts("-1");
				exit(0);
			}else{
				b[i]=b[st[top]];
				ans.EB(b[i],i);
				st2[++top2]=i;
				--top;
			}
		}else if(a[i]==3){
			if(top2){
				b[i]=--ind;
				ans.EB(b[i],i);
				ans.EB(b[i],st2[top2]);
				--top2;
				st2[++top2]=i;
			}else if(top){
				b[i]=--ind;
				ans.EB(b[i],i);
				ans.EB(b[i],st[top]);
				--top;
				st2[++top2]=i;
			}
			else{
				puts("-1");
				exit(0);
			}
		}
	}
	pt(SZ(ans),'\n');
	for(auto x:ans)pt(x.fi,' '),pt(x.se,'\n');
	return 0;
}