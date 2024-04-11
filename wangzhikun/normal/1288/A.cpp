#include <bits/stdc++.h>
 
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
 
int T;
int main() {
	read(T);
	while(T--){
		int n,d;
		read(n);read(d);
		int x = 0,mi = d;
		while(1){
			x+=1;
			if(x+(d+x)/(x+1)>mi)break;
			mi = x+(d+x)/(x+1);
		}
		if(mi<=n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}