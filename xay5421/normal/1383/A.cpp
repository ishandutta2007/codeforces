#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
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
const int N=100005;
int T,n,fa[N],ans;
char A[N],B[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
void ae(int k1,int k2){
	if(fd(k1)!=fd(k2)){
		++ans;
		fa[fd(k1)]=fa[fd(k2)];
	}
}
signed main(){
	rd(T);
	while(T--){
		rd(n);
		scanf("%s%s",A+1,B+1);
		rep(i,0,25)fa[i]=i;
		bool ok=1;
		ans=0;
		rep(i,1,n){
			if(A[i]>B[i]){
				ok=0;
			}
			if(A[i]==B[i])continue;
			ae(A[i]-'a',B[i]-'a');
		}
		if(!ok){
			puts("-1");
			continue;
		}
		pt(ans,'\n');
	}
	return 0;
}