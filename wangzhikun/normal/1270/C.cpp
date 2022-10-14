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

int T,n;
ll a[100010];
int main() {
	read(T);
	while(T--){
		read(n);
		ll csum = 0,cxor = 0;
		for(int i=0;i<n;i++){
			read(a[i]);
			csum+=a[i];
			cxor^=a[i];
		}
		ll cad = 0;
		if(csum%2 == 1){
			cad = (1ll<<55)+1;
		}else{
			cad = 1ll<<55;
		}
		cout<<3<<endl;
		cout<<cad<<' ';
		csum+=cad;
		cxor^=cad;
		ll dif = cxor*2-csum;
		cout<<dif/2<<' '<<dif/2<<endl;
	}
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/