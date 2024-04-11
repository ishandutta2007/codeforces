#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=5005;
int n,cnt[N][26],v[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	double ans=0;
	int all=0;
	rep(c,'a','z'){
		fill(v+1,v+1+n,0);
		int tot=0;
		rep(i,1,n)if(s[i]==c){
			++tot;
			rep(j,1,n){
				int t=++cnt[j][s[(i+j-1)%n+1]-'a'];
				if(t==1){
					++v[j];
				}else if(t==2){
					--v[j];
				}
			}
		}
		if(!tot)continue;
		all+=tot;
		int cur=*max_element(v+1,v+1+n);
		ans+=cur;
		rep(i,1,n)if(s[i]==c){
			rep(j,1,n){
				--cnt[j][s[(i+j-1)%n+1]-'a'];
			}
		}
	}
	printf("%.20f\n",ans/all);
	return 0;
}