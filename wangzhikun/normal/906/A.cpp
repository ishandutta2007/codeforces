#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
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
int n;
char a,b[100010];
int main() {
	read(n);
	int psb = (1<<26)-1;
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int m = strlen(b);
		if(__builtin_popcount(psb) == 1 && a!='.'){
			ans+=1;
		}
		if(a == '.' || a == '?'){
			int cc = 0;
			for(int i=0;i<m;i++)
				cc|=1<<(b[i]-'a');
			cc = (1<<26)-1-cc;
			psb&=cc;
		}
		if(a == '!'){
			int cc = 0;
			for(int i=0;i<m;i++)
				cc|=1<<(b[i]-'a');
			psb&=cc;
		}
	}
	cout<<max(ans-1,0)<<endl;
	return 0;
}