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
int n;

inline bool check(int x){
	for(int i = 1;i <= x;++i)
		if(s[i] != s[i+x]) return false;
	return true;
}

int main(){
	n = read();
	scanf("%s",s+1);
	for(int j = n/2;j >= 1;--j){
		if(check(j)){
			printf("%d\n", j+1+n-j*2);
			return 0;
		}
	}
	printf("%d\n", n);
	return 0;
}