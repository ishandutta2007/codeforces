#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int T,n,d;
int main() {
	read(T);
	while(T--){
		int n,d,a[101];
		read(n,d);
		int ans = 0;
		
		for(int i=0;i<n;i++){
			read(a[i]);
		}
		for(int i=0;i<n;i++){
			if(i*a[i]<=d){
				d-=i*a[i];
				ans+=a[i];
			}else{
				ans+=d/i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}