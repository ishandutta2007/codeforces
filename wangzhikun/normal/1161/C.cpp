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

int n,a[50];
int main() {
	int n,mi = 1e9,cnt = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<mi)mi = a[i];
	}
	for(int i=0;i<n;i++)if(a[i]>mi)cnt++;
	if(cnt>=n/2){
		cout<<"Alice\n";
	}else{
		cout<<"Bob\n";
	}
	return 0;
}