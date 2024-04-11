#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
char s[105][105];
int ans[105][105];
char to_char(int x){
	if(x>=1&&x<=10)return x-1+'0';
	x-=10;
	if(x>=1&&x<=26)return x-1+'a';
	x-=26;
	assert(x>=1&&x<=26);
	return x-1+'A';
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,K;
		scanf("%d%d%d",&n,&m,&K);
		int tt=0;
		rep(i,1,n){
			scanf("%s",s[i]+1);
			tt+=count(s[i]+1,s[i]+1+m,'R');
		}
		int low=tt/K,cnt=K-tt%K,now=1,cur=0;
		rep(i,1,n){
			int a,b,c;
			if(i&1){
				a=1,b=m+1,c=1;
			}else{
				a=m,b=0,c=-1;
			}
			for(int j=a;j!=b;j+=c){
				ans[i][j]=now;
				cur+=s[i][j]=='R';
				if(cur==low&&cnt){
					if(now<K)now+=1;
					cur=0;
					cnt-=1;
				}else if(cur==low+1){
					if(now<K)now+=1;
					cur=0;
				}
			}
		}
		rep(i,1,n){
			rep(j,1,m)putchar(to_char(ans[i][j]));
			putchar('\n');
		}
	}

	return 0;
}