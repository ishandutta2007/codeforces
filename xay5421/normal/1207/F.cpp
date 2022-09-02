#include <cmath>
#include <cstdio>

const int MAXSQR=710;
const int MAXN=500005;

int n,m,b,res;
int A[MAXN],s[MAXSQR][MAXSQR];

inline char readc(){
	char ch;
	while (ch=getchar(),ch!='1' && ch!='2');
	return ch;
}

template <typename T>
inline void read(T &x){
	bool fl=0; char ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	n=500000,read(m); b=sqrt(500000);
	int x,y;
	while (m--){
		switch (readc()){
			case '2' :
				read(x),read(y);
				if (x<=b) printf("%d\n",s[x][y]);
				else{
					res=0;
					for (int i=y;i<=n;i+=x)
						res+=A[i];
					printf("%d\n",res);
				}
				break;
			case '1' :
				read(x),read(y);
				for (int i=1;i<=b;i++)
					s[i][x%i]+=y;
				A[x]+=y;
				break;
		}
	}
	return 0;
}