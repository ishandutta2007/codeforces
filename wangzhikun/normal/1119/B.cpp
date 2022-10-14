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

ll n,a[1010],h;
int main() {
	read(n);read(h);
	for(int i=0;i<n;i++)read(a[i]);
	a[n] = 1e12;
	n+=1;
	for(int l=1;l<=n;l++){
		sort(a,a+l);
		ll csu = 0;
		for(int j = l-1;j>=0;j-=2)csu+=a[j];
		if(csu>h){
			cout<<l-1<<endl;
			break;
		}
	}
	return 0;
}