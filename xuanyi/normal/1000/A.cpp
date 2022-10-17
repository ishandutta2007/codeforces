#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=105;

int n,res;
int cnt[105][26];
string a[MAXN],b[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int main(){
	read(n);
	for (int i=1;i<=n;++i){
		cin>>a[i];
		for (int j=0;j<a[i].size();++j){
			++cnt[j][a[i][j]-'A'];
		}
	}
	for (int i=1;i<=n;++i){
		cin>>b[i];
		for (int j=0;j<b[i].size();++j)
			if (cnt[j][b[i][j]-'A']){
				--cnt[j][b[i][j]-'A'];
			} else ++res;
	}
	printf("%d\n",res);
	return 0;
}