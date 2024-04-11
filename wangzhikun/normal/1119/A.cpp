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

int n,a[300030];
int main() {
	
	read(n);
	int ans = 0;
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	for(int i=0;i<n;i++){
		if(a[i]!=a[0]){
			ans = max(ans,i);
		}
		if(a[i]!=a[n-1]){
			ans = max(ans,n-1-i);
		}
	}
	cout<<ans<<endl;
	return 0;
}