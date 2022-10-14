#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll a,b,c;
int main() {
	read(a);read(b);read(c);
	if(a == b){
		cout<<a+b+c*2<<endl;
	}else{
		cout<<min(a,b)*2+c*2+1<<endl;
	}
	return 0;
}