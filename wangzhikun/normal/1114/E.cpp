#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int rnd(){
	return abs((rand()<<16)+rand());
}
int n,vis[1000010];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main() {
	srand(time(0));
	read(n);
	if(n<57){
		int base = -1,ggg = -1,ccc,mi;
		for(int i=1;i<=n;i++){
			cout<<"? "<<i<<endl;cout.flush();
			if(base == -1){
				cin>>base;
				mi = base;
			}else{
				cin>>ccc;
				if(ggg == -1)ggg = abs(ccc-base);
				ggg = gcd(ggg,abs(ccc-base));
				mi = min(ccc,mi);
			}
			
		}
		cout<<"! "<<mi<<' '<<ggg<<endl;
		return 0;
	}
	int base = -1,ggg = -1,ccc;
	for(int i=0;i<27;i++){
		int c;
		while(1){
			c = rnd()%n+1;
			if(!vis[c])break;
		}
		vis[c] = 1;
		cout<<"? "<<c<<endl;cout.flush();
		if(base == -1){
			cin>>base;
		}else{
			cin>>ccc;
			if(ggg == -1)ggg = abs(ccc-base);
			ggg = gcd(ggg,abs(ccc-base));
		}
	}
	int l = 0,r = 1e9;
	while(l+1<r){
		int mid = (l+r)/2;
		cout<<"> "<<mid<<endl;cout.flush();
		cin>>ccc;
		if(ccc){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout<<"! "<<r-ggg*(n-1)<<' '<<ggg<<endl;
	return 0;
}