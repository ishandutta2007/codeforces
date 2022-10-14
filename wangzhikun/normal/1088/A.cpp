#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}

int main() {
	int x;
	cin>>x;
	if(x == 1){
		cout<<-1<<endl;
	}else{
		cout<<x<<' '<<x<<endl;
	}
	return 0;
}