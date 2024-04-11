#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>pii;typedef vector<int>VI;typedef vector<pii>VP;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=2000005;
int T,n,nn,h[N];char s[N],t[N];
signed main(){
	rd(T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		int L=1,R=n;
		while(L<R&&s[L]==s[R])++L,--R;
		if(L>=R){rep(i,1,n)putchar(s[i]);putchar('\n');continue;}
		t[0]='!';
		nn=n,n=0;
		rep(i,L,R)t[++n]=s[i],t[++n]='@';t[n]='#',--n;
		int pos=0,r=0;
		int res=0,ans=-1;
		rep(i,1,n){
			if(r>i)h[i]=min(h[pos-(i-pos)],r-i);else h[i]=1;
			while(t[i-h[i]]==t[i+h[i]])++h[i];
			if(i+h[i]>r)pos=i,r=i+h[i];
			if(i-h[i]==0||i+h[i]==n+1){
				if(h[i]-1>ans){
					ans=h[i]-1;
					res=i;
				}
			}
		}
		rep(i,1,L-1)putchar(s[i]);
		rep(i,res-h[res],res+h[res])if(t[i]>='a'&&t[i]<='z')putchar(t[i]);
		rep(i,R+1,nn)putchar(s[i]);
		putchar('\n');
	}
	return 0;
}