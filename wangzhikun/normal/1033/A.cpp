#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}

int n,ax,ay,bx,by,cx,cy;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>bx>>by>>ax>>ay>>cx>>cy;
	int ans = 1;
	while(!(ax == cx && ay == cy)){
		if(ax == bx || ay == by)ans = 0;
		if(ax<cx)ax++;
		if(ay<cy)ay++;
		if(ax>cx)ax--;
		if(ay>cy)ay--;
		
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}