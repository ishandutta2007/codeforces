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

int T,n,a[100010];

int main() {
	read(T);
	while(T--){
		read(n);
		int ans1 = 0,mx = -1,mi = 1e9+7;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(!i)continue;
			if(a[i]!=-1){
				if(a[i-1] == -1){
					mx = max(mx,a[i]);
					mi = min(mi,a[i]);
				}else{
					ans1 = max(ans1,abs(a[i]-a[i-1]));
				}
			}else{
				if(a[i-1] != -1){
					mx = max(mx,a[i-1]);
					mi = min(mi,a[i-1]);
				}
			}
		}
		ans1 = max(ans1,(mx-mi+1)/2);
		cout<<ans1<<' '<<(mx+mi)/2<<endl;
	}
	return 0;
}