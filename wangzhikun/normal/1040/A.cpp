// Author : WangZhikun
// Date   : 2018.09.06

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

int n,a[2],m[30],ans = 0;
int main(){
	read(n);read(a[0]);read(a[1]);
	for(int i=0;i<n;i++){
		read(m[i]);
	}
	if(n%2 && m[n/2] == 2)ans+=min(a[0],a[1]);
	for(int i=0;i<n/2;i++){
		if(m[i] == 2 || m[n-1-i] == 2){
			if(m[i]+m[n-1-i] == 4){
				ans+=2*min(a[0],a[1]);
			}else{
				ans+=a[min(m[i],m[n-1-i])];
			}
		}else{
			if(m[i]!=m[n-i-1])ans-=100000000;
		}
	}
	if(ans<0)ans = -1;
	cout<<ans<<endl;
	return 0;
}