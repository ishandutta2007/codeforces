#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=300005;

int n,sum,len,st[N],ans[N*5][3];

struct ff{
	int x,id;
	bool operator<(const ff&b)const{return x<b.x;}
}s[N],t[N];

signed main(){
	rd(n);
	rep(i,1,n)rd(s[i].x),s[i].id=i,sum+=s[i].x;
	rep(i,1,n)rd(t[i].x),t[i].id=i,sum-=t[i].x;
	if(sum){puts("NO");return 0;}
	std::sort(s+1,s+1+n),std::sort(t+1,t+1+n);
	for(int i=n;i>=1;--i){
		if(s[i].x>t[i].x){
			st[++*st]=i;
		}else if(s[i].x<t[i].x){
			if(!*st){puts("NO");return 0;}
			while(*st){
				int tp=st[*st];
				int dt=std::min(t[i].x-s[i].x,s[tp].x-t[tp].x);
				s[i].x+=dt,s[tp].x-=dt,ans[++len][0]=s[tp].id,ans[len][1]=s[i].id,ans[len][2]=dt;
				if(s[tp].x-t[tp].x==0)--*st;else break;
				if(s[i].x==t[i].x)break;
			}
		}
	}
	if(*st){puts("NO");return 0;}
	puts("YES");
	printf("%d\n",len);
	for(int i=1;i<=len;++i)pt(ans[i][1],' '),pt(ans[i][0],' '),pt(ans[i][2],'\n'); 
	return 0;
}