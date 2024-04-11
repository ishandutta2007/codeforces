#include<cstdio>
#include<string>
#include<iostream>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=10005;
int q,vis[N],sg[N];
signed main(){
	rd(q);
	while(q--){
		int n,k;rd(n),rd(k);
		if(n==0){puts("Bob");continue;}
		if(k%3==0){
			if(n%(k+1)==k||n%(k+1)%3){
				puts("Alice");
			}else{
				puts("Bob");
			}
		}else{
			if(n%3){
				puts("Alice");
			}else puts("Bob");
		}
//		for(int i=0;i<=n;++i)sg[i]=0;
//		rep(i,1,n){
//			if(i-1>=0)vis[sg[i-1]]=1;
//			if(i-2>=0)vis[sg[i-2]]=1;
//			if(i-k>=0)vis[sg[i-k]]=1;
//			for(int j=0;j<=4;++j){
//				if(!vis[j]){
//					sg[i]=j;
//					break;
//				}
//			}
//			if(i-1>=0)vis[sg[i-1]]=0;
//			if(i-2>=0)vis[sg[i-2]]=0;
//			if(i-k>=0)vis[sg[i-k]]=0;
//		}
//		if(!sg[n])puts("Bob");else puts("Alice");
	}
	return 0;
}