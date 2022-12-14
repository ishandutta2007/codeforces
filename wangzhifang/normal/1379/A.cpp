#include <cstdio>
#include <cstring>
#define max_len 50
using namespace std;
char s[max_len+2];
char bak[max_len+2];
int mayb[max_len+1];
char t[8]="abacaba";
void test(){
	int n,cnt1=0,cnt2=0;
	scanf("%d\n%s",&n,s+1);
	if(n<7){
		puts("No");
		return;
	}
	for(int i=0,flg=1; ++i<=n-6; flg?(flg==1?++cnt1:mayb[++cnt2]=i):(flg=1))
		for(int j=-1; ++j<7; )
			if(s[i+j]!=t[j])
				if(s[i+j]=='?')
					flg=2;
				else{
					flg=0;
					break;
				}
	if(cnt1>1||cnt1==0&&cnt2==0){
		puts("No");
		return;
	}
	if(cnt1==1){
		puts("Yes");
		for(int i=0; ++i<=n; putchar(s[i]=='?'?'d':s[i]));
		puts("");
		return;
	}
	for(int i=0,u,cnt3; ++i<=cnt2; memcpy(s,bak,sizeof(bak))){
		u=mayb[i],memcpy(bak,s,sizeof(bak)),cnt3=0;
		for(int j=-1; ++j<7; )
			if(s[u+j]=='?')
				s[u+j]=t[j];
		for(int i=0,flg=1; ++i<=n-6; flg?(++cnt3):(flg=1))
			for(int j=-1; ++j<7; )
				if(s[i+j]!=t[j]){
					flg=0;
					break;
				}
		if(cnt3==1){
			puts("Yes");
			for(int i=0; ++i<=n; putchar(s[i]=='?'?'d':s[i]));
			puts("");
			return;
		}
	}
	puts("No");
}
int main(){
	int t;
	scanf("%d",&t);
	for(++t; --t; test());
	return 0;
}