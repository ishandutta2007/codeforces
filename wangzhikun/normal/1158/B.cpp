#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k;
int main() {
	cin>>n>>k;
	int diff = (n-k)/2,cd = 0;
	cd = diff;
	while(n--){
		putchar('0'+(cd == 0));
		cd--;
		if(cd == -1)cd = diff;
	}
	puts("");
	return 0;
}
/*
	10 10
	1111111111
 	10 2
	1010000000
 	10 4
	1010100000
 
*/