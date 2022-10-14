//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n,a[100010];
int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	sort(a,a+n);
	int link =0 ;
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(a[i]<i){
			cout<<"cslnb"<<endl;
			return 0;
		}
		if(a[i]+1 == a[i+1] && a[i+2] == a[i+1] && i<n-2)link+=1;
		if(a[i] == a[i+1] && i<n-1)link+=1;
		ans+=a[i]-i;
	}
	if(link>1){
		cout<<"cslnb"<<endl;
		return 0;
	}
	if(ans%2 == 0){
		cout<<"cslnb"<<endl;
			return 0;
	}else{
		cout<<"sjfnb"<<endl;
			return 0;
	}
	return 0;
}