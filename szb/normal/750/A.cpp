#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("A.txt","r",stdin);
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
	int n,k;
	scanf("%d%d",&n,&k);
	k=240-k;
	int i,sum=0;
	if (k<5)
		return puts("0"),0;
	for(i=1;i<n;i++){
		sum+=5*i;
		if (sum+5*i+5>k)
			break;
	}
	printf("%d",i);
}