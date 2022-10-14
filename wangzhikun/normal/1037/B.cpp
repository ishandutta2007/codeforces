// Author : WangZhikun
// Date   : 2018.09.03

#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}

ll n,a[200020],s,ans;
int main(){
	read(n);read(s);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	sort(a,a+n);
	
	if(a[(n-1)/2]<s){
		for(int i=(n-1)/2;i<n;i++){
			if(a[i]<s)ans+=s-a[i];
		}
	}else{
		for(int i=(n-1)/2;i>=0;i--){
			if(a[i]>s)ans+=a[i]-s;
		}
	}
	cout<<ans<<endl;
	return 0;
}