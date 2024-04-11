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

ll T,a,b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(a-b>1){
			cout<<"NO"<<endl;
		}else{
			ll c = a+b,ans = 0;
			for(ll i = 2;i*i<=c;i++)if(c%i == 0)ans = 1;
			if(ans){
				cout<<"NO"<<endl;
			}else{
			cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}