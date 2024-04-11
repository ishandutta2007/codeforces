#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3e5;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}	
	In void write(int x){
		if(x < 0)x = -x,putchar('-');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int n,k;
int ans[N+5];
char s[N+5];

bool check(){
	memset(ans,-1,sizeof(int) * (k+1));
	for(rg int i = 1;i <= n;i++)if(s[i] != '?'){
		int id = i % k + 1;
		if(ans[id] == -1 || ans[id] == s[i] - '0')ans[id] = s[i] - '0';
		else return 0;		
	}
	int cnt0 = 0,cnt1 = 0;
	for(rg int i = 1;i <= k;i++){
		if(ans[i] == 0)cnt0++;
		if(ans[i] == 1)cnt1++;
	}
	if(cnt0 > (k>>1) || cnt1 > (k>>1))return 0;
	return 1;
}

int main(){
//	freopen("CF1404A.in","r",stdin);
//	freopen("CF1404A.out","w",stdout);
	
	int T = read();
	while(T--){
		n = read(),k = read();
		scanf("%s",s + 1);
		if(check())puts("YES");else puts("NO");
	}
	
	return 0;
}