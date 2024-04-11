//  Created by  on 2018/8/18.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,q,x,y;
int main() {
	read(n);read(q);
	while(q--){
		read(x);read(y);
		ll pre = 0;
		pre = ((x-1)/2)*n;
		if(!(x%2)){
			if((x+y)%2){
			pre+=n/2;
			}else{
				pre+=n-(n/2);
			}
		}
		if((x+y)%2){
			cout<<pre+(n*n+1)/2+(y+1)/2<<endl;
		}else{
			cout<<pre+(y+1)/2<<endl;
		}
	}
	return 0;
}