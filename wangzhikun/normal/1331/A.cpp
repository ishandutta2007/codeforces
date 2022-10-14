#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<endl
#define all(x) x.begin(),x.end()
#define MP make_pair
#define PB push_back

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-'0';ch =getchar();}x*=f;
}

int main(){
	cout<<"No"<<endl;
	return 0;
}