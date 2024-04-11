#include <cstdio>
#include <algorithm>

#define MAXN 1005

int n;

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

struct ele{
	int s,id;
	inline bool operator <(const ele &v)const{
		return s>v.s || (s==v.s && id<v.id);
	}
} A[MAXN];

int main(){
	read(n);
	for (int i=1,x;i<=n;i++){
		read(x),A[i].s+=x;
		read(x),A[i].s+=x;
		read(x),A[i].s+=x;
		read(x),A[i].s+=x;
		A[i].id=i;
	}
	std :: sort(A+1,A+1+n);
	for (int i=1;i<=n;i++){
		if (A[i].id==1){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}