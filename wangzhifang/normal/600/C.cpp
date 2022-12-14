#include <cstdio>
#include <cstring>
using namespace std;
#define max_n 200000
int sum[26];
char str[max_n+1];
int v[max_n+1];
int main(){
	scanf("%s",str);
	int siz=strlen(str);
	int cnt=0;
	memset(sum,0,sizeof(sum));
	for(int i=0; i<siz; ++i)
		++sum[str[i]-'a'];
	for(int i=0; i<26; ++i)
		if(sum[i]&1)
			v[++cnt]=i;
	if((cnt&1)){
		int t=(cnt>>1)+1;
		for(int i=1; i<t; ++i)
			++sum[v[i]];
		for(int i=cnt; i>t; --i)
			--sum[v[i]];
	}
	else{
		int t=cnt>>1;
		for(int i=1; i<=t; ++i)
			++sum[v[i]];
		for(int i=cnt; i>t; --i)
			--sum[v[i]];
	}
	int flg=-1;
	for(int i=0; i<26; ++i){
		if(sum[i]&1)
			flg=i;
		for(int j=sum[i]/2; j; --j)
			putchar('a'+i);
	}
	if(~flg)
		putchar('a'+flg);
	for(int i=25; i>=0; --i)
		for(int j=sum[i]/2; j; --j)
			putchar('a'+i);
	putchar('\n');
	return 0;
}