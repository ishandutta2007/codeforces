// author: xay5421
// created: Sun Sep 12 22:39:53 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int T,n;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		auto chk1=[&]()->int{
			int l=1,r=n;
			while(l<=r&&s[l]=='1')++l;
			while(l<=r&&s[r]=='1')--r;
			rep(i,l,r)if(s[i]=='1')return 0;
			return 1;
		};
		if(count(s+1,s+1+n,'0')==0){
			puts("0");
		}else if(chk1()){
			puts("1");
		}else puts("2");
	}
	return 0;
}