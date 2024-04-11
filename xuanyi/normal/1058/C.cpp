#include <cstdio>

const int MAXN=105;

int n,S;
int a[MAXN];

template <typename T>
inline void read(T &x){
	int ch;
	while (ch=getchar(),ch<48 || 57<ch); x=(ch&15);
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

inline bool check(int x){
	int cnt=0;
	for (int i=1,j=1;i<=n;i=j){
		int sum=0; ++cnt;
		while (j<=n && (sum<x || a[j]==0)) sum+=a[j++];
		if (sum!=x) return 0;
	}
	return cnt>1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) read(a[i]),S+=a[i];
	if (S==0){puts("YES");return 0;}
	for (int i=1;i<=n*9;++i)
		if (check(i)) return puts("YES"),0;
	return puts("NO"),0;
}