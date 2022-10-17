#include <cstdio>
#define __R register
typedef long long ll;

int n;
ll l,r;

inline char getc(){
	static const int IN_LEN=10000000;
    static char buf[IN_LEN],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,IN_LEN,stdin),p1==p2) ? EOF: *p1++;
}

template <typename T>
inline void read(T &x){
	x=0; __R char ch; __R bool flg=0;
	while (ch=getc(),ch<48 || 57<ch) flg^=ch=='-'; x=(ch&15);
	while (ch=getc(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (flg) x=-x;
}

template <typename T>
inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}


int main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(l),read(r);
		for (int bit=0;;bit++){
			if (!(l>>bit&1)){
				l^=1ll<<bit;
				if (r<l){
					l^=1ll<<bit;
					break;
				}
			}
		}
		write(l),putchar('\n');
	}
	return 0;
}