//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=4005;

int T,n,cnt1[4],cnt2[4],ans[N],s[N],t[N],q[N];
char _s[N],_t[N];

int ra(){
	return rand()&0x7fff;
}

int brand(){
	return (ra()<<16)+(ra()<<1)+(ra()&1); 
}

void push(int x){
	if(x&1)debug("ERR\n");
	if(!x)return;
	std::reverse(s+1,s+1+x);
	if(*ans&&ans[*ans]==x){--*ans;return;}
	ans[++*ans]=x;
}

bool solve(){
	*ans=0;
	rep(i,1,n)s[i]=_s[i]-'0';
	for(int i=n-1;i>=1;i-=2){
		if(s[i]!=t[i]||s[i+1]!=t[i+1]){
			if(i==1){
				push(2);
				continue;
			}
			*q=0;
			for(int j=1;j<i;j+=2)if(s[j]==t[i]&&s[j+1]==t[i+1]){
				q[++*q]=j;
			}
			if(*q==0){
				for(int j=1;j<i;j+=2)if(s[j]==(t[i]^1)&&s[j+1]==(t[i+1]^1)){
					q[++*q]=j;
				}
				if(!*q)push(i+1);
				else push(q[brand()%*q+1]+1);
				*q=0;
				for(int j=1;j<i;j+=2)if(s[j]==t[i]&&s[j+1]==t[i+1]){
					q[++*q]=j;
				}
			}
			int j=q[brand()%*q+1];
			if(s[j]==t[i]&&s[j+1]==t[i+1]){
				push(j+1);
				push(i+1);
			}
		}
	}
	return *ans<=n+1;
}

signed main(){
	rd(T);
	while(T--){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		*ans=0;
		scanf("%s%s",_s+1,_t+1);
		n=strlen(_s+1);
		rep(i,1,n)s[i]=_s[i]-'0',t[i]=_t[i]-'0';
		for(int i=1;i<=n;i+=2){
			++cnt1[s[i]+s[i+1]];
			++cnt2[t[i]+t[i+1]];
		}
		bool flag=1;
		rep(i,0,2)if(cnt1[i]!=cnt2[i]){
			flag=0;
		}
		if(!flag){puts("-1");continue;}
		while(!solve());
		pt(*ans,'\n');
		rep(i,1,*ans)pt(ans[i],' ');putchar('\n');
		rep(i,1,n){
			if(s[i]!=t[i]){
				debug("!\n");
				while(1);
			}
			s[i]=0,t[i]=0;
		}
	}
	return 0;
}