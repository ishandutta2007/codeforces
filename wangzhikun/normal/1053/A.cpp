#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}
	x*=f;
}

ll a,b,k,re = 0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
	read(a);read(b);read(k);
	//cout<<k<<endl;
	if(k%2 == 0)k/=2;
	else re = 1;
	while(1){
		ll d = max(gcd(k,a),gcd(k,b));
	//	cout<<d<<endl;
		if(d==1)break;
		if(a%d == 0){
			a/=d;
			k/=d;
			if(re){
				a*=2;re =0;
			}
		}else{
			b/=d;
			k/=d;
			if(re){
				b*=2;re =0;
			}
		}
	}
//	cout<<k<<endl;
	if(k == 1){
		cout<<"YES"<<endl;
		if(re)if(a<b)a*=2;else b*=2;
		cout<<"0 0\n0 "<<b<<"\n"<<a<<" 0"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}