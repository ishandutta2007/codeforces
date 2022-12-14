#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
char s[501],t[1000];
il void test(){
	scanf("\n%s\n%s",s,t);
	int n=strlen(s),m=strlen(t);
	reverse(t,t+m);
	int mx=1;
	for(int i=3; i<=m; i+=2){
		bool flg=1;
		for(int l=m-i,r=m-1; l<r; ++l,--r)
			if(t[l]!=t[r]){
				flg=0;
				break;
			}
		if(flg)
			mx=i;
	}
	int mm=m;
	m=m-(mx-1)/2;
	for(int i=n-m; i>=0; --i){
		bool flg=1;
		for(int j=m; --j>=0; )
			if(t[j]!=s[i+j]){
				flg=0;
				break;
			}
		if(flg){
			puts("YES");
			return;
		}
	}
	m=mm;
	reverse(t,t+m);
	mx=1;
	for(int i=3; i<=m; i+=2){
		bool flg=1;
		for(int l=m-i,r=m-1; l<r; ++l,--r)
			if(t[l]!=t[r]){
				flg=0;
				break;
			}
		if(flg)
			mx=i;
	}
	m=m-(mx-1)/2;
	for(int i=n-m; i>=0; --i){
		bool flg=1;
		for(int j=m; --j>=0; )
			if(t[j]!=s[i+j]){
				flg=0;
				break;
			}
		if(flg){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}