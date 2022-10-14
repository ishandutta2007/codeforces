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
const int N = 200020;
int n,a[N];

int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		a[i] = abs(a[i]);
	}
	sort(a,a+n);
	ll ans = 0;
	int p = -1;
	for(int i=0;i<n;i++){
		while(p<n-1 && a[p+1]<=a[i]*2){
			p++;
		}
		ans+=p-i;
	}
	cout<<ans<<endl;
	return 0;
}