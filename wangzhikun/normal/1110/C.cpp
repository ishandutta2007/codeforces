#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,cc,pans[30] = {0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(cc);
		int j = 0;
		while((1<<j)<=cc)j++;
		if(cc!=(1<<j)-1){
			cout<<(1<<j)-1<<endl;
		}else{
			cout<<pans[j-1]<<endl;
		}
	}
	return 0;
}