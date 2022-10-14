#include <set>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;

ll n,a,b,k;
ll B = 1e9+9;

ll pw(ll a,ll b){
	ll an = 1,cu = a;
	for(ll i=0;i<30;i++){
		if((1<<i)&b){
			an = an*cu%B;
		}
		cu = cu*cu%B;
	}
	return an;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b!=0){
		d = exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x = 1; y = 0;
	}
	return d;
}
ll inv(ll a,ll n){
	ll d,x,y;
	d = exgcd(a,n,x,y);
	return d==1 ? (x+n)%n : -1;
}
char cc[100010];
int main() {
	//cout<<pw(2,3)<<endl;
	cin>>n>>a>>b>>k;
	cin>>cc;
	//cout<<"3"<<endl;
	ll sta = pw(a,n),ec = (inv(a,B)*b)%B,csu = 0,ans = 0;
	int tgt = (int)sqrt(n+1);
	while(k<tgt){
		for(int i=0;i<k;i++) cc[i+k] = cc[i];
		k = k*2;
	}
	//cout<<sta<<endl;
	ll cpos = sta;
	for(int i=0;i<k;i++){
		//cout<<cpos<<endl;
		if(cc[i] == '+'){
			csu+=cpos;
		}else{
			csu-=cpos;
		}
		csu%=B;
		cpos = cpos*ec%B;
	}
	
	ll esu = csu*inv(sta,B)%B,estep = pw(ec,k);
	cpos = sta;
	int clog = 0;
	while(clog+k<n+1){
		//cout<<"go"<<endl;
		ans+=esu*cpos%B;
		ans=(ans+B)%B;
		clog+=k;
		cpos = cpos*estep%B;
	}
	for(int i=clog;i<n+1;i++){
		if(cc[i%k] == '+'){
			ans+=cpos;
		}else{
			ans-=cpos;
		}
		ans=(ans+B)%B;
		cpos = cpos*ec%B;
	}
	cout<<(ans+B)%B<<endl;
	return 0;
}