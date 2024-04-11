#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 50;

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
}
using namespace IO;

char A[N+5];
int a[N+5],b[N+5],n;

bool check(int a0,int a1,int a2){
	for(rg int i = 1;i <= n;i++){
		if(a[i] == 0)b[i] = a0;
		else if(a[i] == 1)b[i] = a1;
		else b[i] = a2;
	}
	int top = 0;
//for(rg int i = 1;i <= n;i++)cout<<b[i]<" ";cout<<endl;
	for(rg int i = 1;i <= n;i++){
		top += b[i];
		if(top < 0)return 0;
	}
	if(top != 0)return 0;
	return 1;
}
bool solve(){
	scanf("%s",A + 1);
	n = strlen(A + 1);
	for(rg int i = 1;i <= n;i++)a[i] = A[i] - 'A';
	if(check(1,1,-1))return 1;
	if(check(1,-1,1))return 1;
	if(check(1,-1,-1))return 1;
	if(check(-1,1,-1))return 1;
	if(check(-1,-1,1))return 1;
	if(check(-1,1,1))return 1;
	return 0;
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--){
		if(solve())puts("YES");
		else puts("NO");
	}
	return 0;
}