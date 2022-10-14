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

int main(){
	int n,su = 0,x = 1,ans = 0;
	cin>>n;
	while(su+x<n){
		su+=x;
		ans+=1;
		x*=2;
	}
	if(su<n)ans+=1;
	cout<<ans<<endl;
	return 0;
}