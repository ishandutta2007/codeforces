#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

char s[N+5];
bool f1[N+5],f2[N+5];
int n;

bool solve(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	f1[1] = 1;
//cout<<"n="<<n<<endl;
	for(rg int i = 2;i <= n;i++){
		f1[i] = f1[i-1];
		if(s[i] == '1' && s[i-1] == '1')f1[i] = 0;
	}
	f2[n] = 1;
	for(rg int i = n - 1;i >= 1;i--){
		f2[i] = f2[i+1];
		if(s[i] == '0' && s[i+1] == '0')f2[i] = 0;
	}
	if(f1[n] || f2[1])return 1;
	for(rg int i = 1;i < n;i++)if(f1[i] && f2[i+1] && !(s[i]=='1'&& s[i+1]=='0'))return 1;
	return 0;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--){
		if(solve())puts("YES");
		else puts("NO");
	}
	
	return 0;
}