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
 
ll T,a,b;
int main() {
	read(T);
	while(T--){
		read(a);read(b);
		int cnt = 0,cp = 0;
		while(1){
			if(cp*10+9<=b){
				cp = cp*10+9;
				cnt+=1;
			}else{
				break;
			}
		}
		cout<<a*cnt<<endl;
	}
	return 0;
}