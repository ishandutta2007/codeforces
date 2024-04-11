//  Created by WangZhikun on 2018/10/4.

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))

using namespace std;
typedef long long ll;

template <typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,ans =0,c = 0;
int main() {
	read(n);
	while(c*10+9<=n){
		c = c*10+9;
		ans+=9;
	}
	n-=c;
	while(n){
	ans+=n%10;
	n/=10;
	}
	cout<<ans<<endl;
	return 0;
}