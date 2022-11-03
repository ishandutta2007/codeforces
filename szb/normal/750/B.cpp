#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("B.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
#else
int readint(){
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++);
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return val;
}
#endif
char readchar(){
	for(;isspace(buf[bufpos]);bufpos++);
	return buf[bufpos++];
}
int readstr(char* s){
	int cur=0;
	for(;isspace(buf[bufpos]);bufpos++);
	for(;!isspace(buf[bufpos]);bufpos++)
		s[cur++]=buf[bufpos];
	s[cur]='\0';
	return cur;
}
int main(){
	init();
	int n=readint(),now=0;
	while(n--){
		int t=readint();
		char c=readchar();
		if ((now==20000 || !now) && (c=='W' || c=='E'))
			return puts("NO"),0;
		if (c=='N')
			now-=t;
		else if (c=='S')
			now+=t;
		if (now>20000 || now<0)
			return puts("NO"),0;
	}
	if (now)
		return puts("NO"),0;
	puts("YES");
}