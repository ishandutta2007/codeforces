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
int n,nxt[N];
ll su[N],s[N],ans[N];
void add(int p,int x){
	while(p<N){
		su[p]+=x;
		p+=p&(-p);
	}
}
int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(s[i]);
		add(i,i);
	}
	for(int i=n;i>=1;i--){
		ll cs = 0,cc = 0;
		for(int a=19;a>=0;a--){
			if(cs+(1<<a) <= n){
				if(cc+ su[cs+(1<<a)]<=s[i]){
					cc+=su[cs+(1<<a)];
					cs+=(1<<a);
				}
			}
		}
		cs+=1;
		ans[i] = cs;
		add(cs,-cs);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}