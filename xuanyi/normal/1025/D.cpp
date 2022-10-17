#include <cstdio>

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putc(x%10+48);
}

const int MAXN=705;

int n;
int a[MAXN];
bool p1[MAXN][MAXN],p2[MAXN][MAXN],f[MAXN][MAXN];

inline int gcd(int a,int b){
	while (a^=b^=a^=b%=a,a);
	return b;
}

int main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i]);
		p1[i][i]=p2[i][i]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (gcd(a[i],a[j])>1) f[i][j]=1;
	for (int L=1;L<=n;L++){
		for (int i=1;i<=n;i++){
			int j=i+L-1;
			if (j>n) break;
			for (int k=i;k<=j;k++){
				if (p1[k][i] && p2[k][j]){
					if (i==1 && j==n)
						return puts("Yes"),0;
					if (f[i-1][k]) p2[i-1][j]=1;
					if (f[j+1][k]) p1[j+1][i]=1;
				}
			}
		}
	}
	puts("No");
	return 0;
}