// author: xay5421
// created: Sun Dec 20 14:36:46 2020
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=500005;
int T,n;
char s[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		vector<int>tt(n*2+1,0);
		int cur=n;
		rep(i,1,n){
			if(s[i]=='1'){
				++tt[cur];
				++cur;
			}
			if(s[i]=='0'){
				--cur;
				++tt[cur];
			}
		}
		cur=n;
		int l=0,r=SZ(tt)-1;
		auto clip=[&](){
			while(l<=r&&!tt[l])++l;
			while(l<=r&&!tt[r])--r;
		};
		clip();
		rep(i,1,n){
			if(tt[cur-1]>0&&!(tt[cur-1]==1&&cur-1<r)){
				--tt[--cur];
				putchar('0');
			}else{
				assert(tt[cur]>0);
				--tt[cur++];
				putchar('1');
			}
			clip();
		}
		puts("");
	}
	return 0;
}