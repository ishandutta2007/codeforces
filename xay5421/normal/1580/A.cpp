// author: xay5421
// created: Thu Sep 30 18:12:21 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=405,INF=0X3F3F3F3F;
int T,n,m,sum[N][N],w1[N],w0[N];
char s[N][N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n){
			scanf("%s",s[i]+1);
		}
		rep(i,1,n){
			rep(j,1,m){
				sum[i][j]=sum[i-1][j]+(s[i][j]=='1');
			}
		}
		int ans=INF;
		rep(i,1,n){
			rep(j,i+4,n){
				int mn=INF;
				rep(k,1,m){
					w1[k]=(j-1-i)-(sum[j-1][k]-sum[i][k]);
					w0[k]=(j-1-i)-w1[k]+(s[i][k]=='0')+(s[j][k]=='0');
					if(k>=4){
						mn=min(mn,w1[k-3]+w0[k-2]+w0[k-1]);
						ans=min(ans,mn+w1[k]);
					}
					mn+=w0[k];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}