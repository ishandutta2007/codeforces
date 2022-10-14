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
int k;
int main() {
	read(k);
	int ccc = max(k/500000,5);
	int ck = k+(ccc-1)*ccc;
	for(int y = 999998;y>0;y--){
		if((ck+y)%ccc == 0){
			cout<<ccc<<endl;
			cout<<y<<' '<<-y-2<<' ';
			for(int i=0;i<ccc-3;i++)cout<<-1<<' ';
			cout<<(ck+y)/ccc<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}