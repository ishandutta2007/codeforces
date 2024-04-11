#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}
ll t,a,b,k,ans;
int main() {
	read(t);
	while(t--){
		read(a);read(b);read(k);
		ans = (k/2)*(a-b);
		if(k%2)ans+=a;
		cout<<ans<<endl;
	}
	return 0;
}