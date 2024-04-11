#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1e5;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n,k;
char s[N+5];

int main(){
//	freopen("C.in","r",stdin);
	int t = read();
	while(t--){
		n = read(),k = read();
		scanf("%s",s + 1);
		sort(s + 1,s + n + 1);
//cout << s + 1 << endl;
		bool b = 1;
		for(rg int i = 1;i < k;i++)if(s[i] != s[i+1])b = 0;
		if(!b){
			putchar(s[k]),putchar('\n');
			continue;
		}
		b = 1;
		for(rg int i = k + 1;i < n;i++)if(s[i] != s[i+1])b = 0;
		if(!b){
			for(rg int i = k;i <= n;i++)putchar(s[i]);
			putchar('\n');
		}
		else{
			int d = ceil(1.0 * n / k);
			for(rg int i = k;i <= k + d - 1;i++)putchar(s[i]);
			putchar('\n');
		}
	}
	return 0;	
}