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

int n;
char s[10010];
int main() {
	cin>>s;
	n = strlen(s);
	int sm = 1;
	for(int i=1;i<n/2;i++){
		if(s[i]!=s[0])sm = 0;
	}
	if(sm){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int j=0;j<n;j++)s[n+j] = s[j];
	for(int i=1;i<n;i++){
		int sm = 1;
		for(int j=0;j<n;j++)if(s[i+j]!=s[j])sm = 0;
		if(sm)continue;
		sm = 1;
		for(int j=0;j<n/2;j++)if(s[i+j] !=s[i+n-1-j])sm = 0;
		if(!sm)continue;
		cout<<1<<endl;
		return 0;
	}
	cout<<2<<endl;
	return 0;
}