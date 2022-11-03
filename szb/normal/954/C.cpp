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

const int N = 200005;
int n,x = 1e9,y = 1e9,lest;
int a[N];

int main(){
	n = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	for(int i = 2;i <= n;++i)
		if(a[i] == a[i-1]){
			puts("NO");
			return 0;
		}
	for(int i = 2;i <= n;++i){
		if(abs(a[i]-a[i-1]) != 1){
			if(y == 1e9){
				y = abs(a[i]-a[i-1]);
			}
			else{
				if(y != abs(a[i]-a[i-1])){
					puts("NO");
					return 0;
				}
			}
		}
	}
	for(int i = 2;i <= n;++i){
		if(abs(a[i]-a[i-1]) == 1){
			if((a[i]-1)/y != (a[i-1]-1)/y){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	printf("%d %d\n",x,y);
	return 0;
}