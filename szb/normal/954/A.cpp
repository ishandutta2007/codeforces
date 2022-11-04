#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
inline void write(int x){
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
inline void writeln(int x){
	write(x); putchar('\n');
}

const int N = 105;
char s[N];
int n,ans;

int main(){
	n = read();
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i = 2;i <= n;++i){
		if(s[i] == 'U' && s[i-1] == 'R') ++ans,++i;
		else if(s[i] == 'R' && s[i-1] == 'U') ++ans,++i;
	}
	printf("%d\n", n-ans);
	return 0;
}