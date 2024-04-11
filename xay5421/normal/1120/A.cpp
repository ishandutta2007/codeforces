#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;}
template<typename T>T pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>T pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
const int N=500005;
int m,k,n,s,tot,a[N],b[N],bin[N],cnt[N],st[N],top;
int main(){
	rd(m),rd(k),rd(n),rd(s);
	rep(i,1,m)rd(a[i]);rep(i,1,s)rd(b[i]),++bin[b[i]];
	for(int i=1,j=1;i<=m;++i){
		while(j<=m&&(j<=i+k-1||tot<s)){
			++cnt[a[j]];
			if(cnt[a[j]]<=bin[a[j]])++tot;
			++j;
		}
		if(j>i+k-1&&tot==s&&(i-1)/k+(m-j+1)/k>=n-1){
			if((i-1)/k<n)for(int p=1;p<=(i-1)%k;++p)st[++top]=p;
			else{
				for(int p=1;p<=(i-1)%k+k*((i-1)/k-n-1);++p)st[++top]=p;
			}
			int tmp=0;
			for(int p=i;p<j;++p)if(bin[a[p]])--bin[a[p]];else if(tmp<j-i-k)st[++top]=p,++tmp;
			printf("%d\n",top);
			for(int i=1;i<=top;++i)printf("%d ",st[i]);
			return 0;
		}
		if(cnt[a[i]]<=bin[a[i]])--tot;
		--cnt[a[i]];
	}
	puts("-1");
	return 0;
}