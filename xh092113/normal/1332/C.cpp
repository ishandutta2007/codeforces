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

char s[2*N+5];
int num[26];

int main(){
//	freopen("C.in","r",stdin);
	int t = read();
	while(t--){
		int ans = 0;
		int n = read(),k = read();
		scanf("%s",s + 1);
		for(rg int pos = 1;pos <= k + 1 - pos;pos++){
			memset(num,0,sizeof(num));
			for(rg int l = 1;l <= n;l += k){
				int r = l + k - 1;
				num[s[l+pos-1]-'a']++;
				num[s[r-pos+1]-'a']++;	
			}
			int maxn = 0;
			for(rg int i = 0;i < 26;i++)maxn = max(maxn,num[i]);
			int all = n / k * 2;
			if(pos == k + 1 - pos)ans += (all - maxn) >> 1;
			else ans += (all - maxn);
//			ans += (all - maxn) / (pos == k + 1 - pos ? 2 : 1);
		}	
		write(ans),putchar('\n');
	}	
	return 0;
}