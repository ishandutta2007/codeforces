#include <iostream>

using namespace std;
typedef long long ll;
int gcd(int a,int b){
	return b != 0?gcd(b,a%b):a;
}
int T,p1,p2,k;
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>p1>>p2>>k;
		int d = gcd(p1,p2);
		p1/=d;
		p2/=d;
		if(p1>p2)swap(p1,p2);
		int lim = (p2+p1-2)/p1;
		if(lim>=k){
			cout<<"REBEL\n";
		}else{
			cout<<"OBEY\n";
		}
	}
	return 0;
}