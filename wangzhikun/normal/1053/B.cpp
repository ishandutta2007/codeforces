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

ll n,a[300030];
int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		ll cc = 0;
		for(int j=0;j<63;j++){
			cc+=a[i]%2;
			a[i]>>=1;
		}
		a[i] = cc;
		//cout<<a[i]<<endl;
	}
	ll cc = 0,c0 = 0,c1 = 0,ans = 0;
	for(int i=0;i<n;i++){
		cc+=a[i];
		if(i>=70){
			if(cc%2 == 0) c0+=1;
			else c1+=1;
		}
	}
	cc = 0;
	ll ccc = 0;
	for(int i=0;i<70;i++)ccc+=a[i];
	for(int i=0;i<n;i++){
		ll csu = 0,cmax = 0;
		for(int j=i;j<=i+70 && j<n;j++){
			csu+=a[j];
			cmax = max(cmax,a[j]);
			if(csu%2 == 0 && cmax*2<=csu)ans+=1;
		}
		if(i+70<n){
			ccc+=a[i+70];
			if(ccc%2 == 0)
				c0-=1;
			else
				c1-=1;
		}
		if(cc%2 == 0)
			ans+=c0;
		else
			ans+=c1;
		cc+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}