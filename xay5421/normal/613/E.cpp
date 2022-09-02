#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=2005,B=31,TT=998244853,P=1e9+7;
int n,m,pw[N],ans;
char s[2][N],t[N];
struct ha{
	int h[N],ih[N];
	void init(char*s,int n){
		rep(i,1,n)h[i]=(1LL*h[i-1]*B+s[i]-'a'+1)%TT;
		per(i,n,1)ih[i]=(1LL*ih[i+1]*B+s[i]-'a'+1)%TT;
	}
	int get(int l,int r,int o){
		if(o==0){
			return(h[r]+TT-1LL*h[l-1]*pw[r-l+1]%TT)%TT;
		}else{
			return(ih[l]+TT-1LL*ih[r+1]*pw[r-l+1]%TT)%TT;
		}
	}
}hs[2],ht;
int u1[2][N][N],u2[2][N][N],f[N][2][2][N];
void addx(int&k1,int k2){
	(k1+=k2)>=P&&(k1-=P);
}
void fun(bool flag){
	memset(u1,0,sizeof(u1));
	memset(u2,0,sizeof(u2));
	hs[0].init(s[0],n);
	hs[1].init(s[1],n);
	ht.init(t,m);
	memset(f,0,sizeof(f));
	rep(i,1,n){
		rep(j,2,i){
			if(j>m/2)break;
			if(hs[0].get(i-j+1,i,1)==ht.get(1,j,0)&&hs[1].get(i-j+1,i,0)==ht.get(j+1,j*2,0)){
				++u1[1][i][j*2];
			}
			if(hs[1].get(i-j+1,i,1)==ht.get(1,j,0)&&hs[0].get(i-j+1,i,0)==ht.get(j+1,j*2,0)){
				++u1[0][i][j*2];
			}
		}
	}
	rep(i,1,n){
		rep(j,2,n-i+1){
			if(j>m/2)break;
			if(hs[1].get(i,i+j-1,0)==ht.get(m-j+1,m,1)&&hs[0].get(i,i+j-1,1)==ht.get(m-j*2+1,m-j,1)){
				++u2[1][i][j*2];
			}
			if(hs[0].get(i,i+j-1,0)==ht.get(m-j+1,m,1)&&hs[1].get(i,i+j-1,1)==ht.get(m-j*2+1,m-j,1)){
				++u2[0][i][j*2];
			}
		}
	}
	if(flag==0){
		rep(i,1,n){
			addx(ans,u1[0][i][m]);
			addx(ans,u1[1][i][m]);
			addx(ans,u2[0][i][m]);
			addx(ans,u2[1][i][m]);
		}
		D(">>> %d\n",ans);
	}
	rep(i,1,n){
		rep(j,0,1){
			rep(k,1,m){
				if(k<m){
					addx(ans,1LL*f[i][j][0][k]*u2[j^1][i][m-k+1]%P);
				}
			}
		}
		rep(j,0,1){
			if(s[j][i]==t[1]){
				addx(f[i][j][0][1],1);
			}
		}
		rep(j,0,1){
			rep(k,1,m){
				if(k<m&&s[j^1][i]==t[k+1]){
					addx(f[i][j^1][1][k+1],f[i][j][0][k]);
				}
			}
		}
		rep(j,0,1){
			addx(ans,f[i][j][0][m]);
			addx(ans,f[i][j][1][m]);
		}
		rep(j,0,1)rep(k,2,m)addx(f[i][j][1][k],u1[j][i][k]);
		rep(j,0,1){
			rep(k,1,m){
				if(i<n&&s[j][i+1]==t[k+1]){
					addx(f[i+1][j][0][k+1],f[i][j][0][k]);
					addx(f[i+1][j][0][k+1],f[i][j][1][k]);
				}
			}
		}
	}
	rep(i,1,n)rep(j,0,1)rep(k,0,1)rep(t,1,m)D("f[%d][%d][%d][%d]=%d\n",i,j,k,t,f[i][j][k][t]);
	D("!!! %d\n",ans);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,N-1)pw[i]=1LL*pw[i-1]*B%TT;
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1);
	n=strlen(s[0]+1);
	m=strlen(t+1);
	if(m==1){
		printf("%d\n",(int)(count(s[0]+1,s[0]+1+n,t[1])+count(s[1]+1,s[1]+1+n,t[1])));
		return 0;
	}
	if(m==2){
		rep(i,1,n){
			if(i<n){
				ans+=(s[0][i]==t[1]&&s[0][i+1]==t[2]);
				ans+=(s[0][i]==t[2]&&s[0][i+1]==t[1]);
				ans+=(s[1][i]==t[1]&&s[1][i+1]==t[2]);
				ans+=(s[1][i]==t[2]&&s[1][i+1]==t[1]);
			}
			ans+=(s[0][i]==t[1]&&s[1][i]==t[2]);
			ans+=(s[0][i]==t[2]&&s[1][i]==t[1]);
		}
		printf("%d\n",ans);
		return 0;
	}
	fun(0);
	reverse(s[0]+1,s[0]+1+n);
	reverse(s[1]+1,s[1]+1+n);
	//reverse(t+1,t+1+m);
	fun(1);
	printf("%d\n",ans);
	return 0;
}