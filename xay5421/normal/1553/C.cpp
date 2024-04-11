// author: xay5421
// created: Thu Jul 22 22:45:58 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T,f[(1<<10)+5];
char s[15];
int main(){
	scanf("%d",&T);
	rep(i,0,(1<<10)-1){
		int dt=0;
		f[i]=10;
		rep(j,0,9){
			if(i>>j&1){
				if(j&1){
					--dt;
				}else{
					++dt;
				}
			}
			if(dt<0&&dt+(0>j)+(2>j)+(4>j)+(6>j)+(8>j)<0){
				f[i]=j+1;
				break;
			}
			if(dt>0&&dt-(1>j)-(3>j)-(5>j)-(7>j)-(9>j)>0){
				f[i]=j+1;
				break;
			}
		}
	}
	while(T--){
		scanf("%s",s);
		int ans=10;
		rep(i,0,(1<<10)-1){
			bool ok=1;
			rep(j,0,9)if(s[j]!='?'&&(s[j]&1)!=(i>>j&1))ok=0;
			if(ok)ans=min(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}