#include<bits/stdc++.h>
using namespace std;
#define ll long long 

priority_queue<int>Q;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')w = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * w;
}

inline void write(ll x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x/10);
	putchar('0' + x%10);
}

int main(){
//	freopen("713C.in","r",stdin);
//	freopen("713C.out","w",stdout);
	int n = read();
	int i = 0,a;
	ll ans = 0;
	while(n--){
		i++;
		a = read() - i;
		Q.push(a);
		if(Q.top() > a){ans += 1ll*(Q.top() - a);Q.pop();Q.push(a);}
	}
	write(ans);
	putchar('\n');
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}