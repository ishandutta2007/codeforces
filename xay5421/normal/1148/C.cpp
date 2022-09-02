#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=300005;

int n,top,p[N],pp[N],ans[5*N][2];

void work(int i,int j){
	ans[++top][0]=i,ans[top][1]=j;
	std::swap(pp[p[i]],pp[p[j]]);
	std::swap(p[i],p[j]);
}

signed main(){
	rd(n);rep(i,1,n)rd(p[i]),pp[p[i]]=i;int mid=n>>1;
	rep(i,1,mid){
		int l=mid-i+1,r=mid+i;
		int posl=pp[l];
		if(posl!=l){
			if(posl>mid)work(posl,1),posl=1;
			work(posl,n),posl=n;
			work(l,posl);
		}
		int posr=pp[r];
		if(posr!=r){
			if(posr<mid)work(posr,n),posr=n;
			work(posr,1),posr=1;
			work(posr,r);
		}
	}
	pt(top,'\n');
	for(int i=1;i<=top;++i)pt(ans[i][0],' '),pt(ans[i][1],'\n');
	return 0;
}