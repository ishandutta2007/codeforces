#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int T,n,a,b,c;
int main() {
	read(T);
	while(T--){
		read(n);read(a);read(b);
		int mx1 = -1,mx2 = -1;
		for(int i=0;i<a;i++){
			read(c);
			mx1 = max(mx1,c);
		}
		for(int i=0;i<b;i++){
			read(c);
			mx2 = max(mx2,c);
		}
		cout<<((mx1>mx2)?"YES":"NO")<<endl;
	}
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/