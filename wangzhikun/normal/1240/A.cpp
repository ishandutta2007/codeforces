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

ll q,v[300030],x,a,y,b;

int main() {
	read(q);
	while(q--){
		int n;
		read(n);
		for(int i=1;i<=n;i++){
			read(v[i]);
			v[i]/=100;
		}
		sort(v+1,v+1+n);
		for(int i=1;i<=n/2;i++)swap(v[i],v[n+1-i]);
		for(int i=2;i<=n;i++)v[i]+=v[i-1];
		read(x);read(a);read(y);read(b);
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		ll k;
		read(k);
		ll cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i=1;i<=n;i++){
			if(i%a == 0){
				if(i%b == 0){
					cnt1++;
				}else{
					cnt2++;
				}
			}else{
				if(i%b == 0){
					cnt3++;
				}
			}
			if(v[cnt1]*(x+y)+(v[cnt1+cnt2]-v[cnt1])*x+(v[cnt1+cnt2+cnt3]-v[cnt1+cnt2])*y>=k){
				cout<<i<<endl;
				goto nxt;
			}
		}
		cout<<-1<<endl;
		nxt:;
	}
	return 0;
}