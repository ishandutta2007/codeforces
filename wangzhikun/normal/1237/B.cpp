#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

const int N = 200020;
int n,a[N],ia[N],ib[N];
int main() {
	read(n);
	for(int i=0;i<n;i++)read(ia[i]);
	for(int i=0;i<n;i++)read(ib[i]);
	for(int i=0;i<n;i++){
		int cu = ia[n-1-i];
		a[cu] = i;
	}
	int cmx = -1,cnt = 0;
	for(int i=0;i<n;i++){
		int cu = ib[n-1-i];
		if(a[cu]<cmx){
			cnt++;
		}
		cmx = max(cmx,a[cu]);
	}
	cout<<cnt<<endl;
	return 0;
}