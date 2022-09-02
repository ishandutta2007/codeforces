#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=200005;

int n,a[N],b[N],ok[N];

signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	int pos=0;
	rep(i,1,n)if(b[i]==1){
		pos=i;rep(j,i+1,n)if(b[j]!=b[j-1]+1){pos=0;break;}
	}
	if(pos){
		rep(i,1,n)ok[a[i]]=1;bool fl=1;
		rep(i,1,pos-1){
			if(!ok[b[n]+i]){
				fl=0;
				break;
			}
			ok[b[i]]=1;
		}
		if(fl)return pt(pos-1,'\n'),0;
	}
	int ans=0;
	rep(i,1,n)if(b[i]){
		if(i-b[i]+1>ans)ans=i-b[i]+1;
	}
	printf("%d\n",n+ans);
	return 0;
}