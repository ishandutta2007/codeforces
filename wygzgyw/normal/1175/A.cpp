#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll n,k,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k);
		ans=0;
		while (n) {
			if (n%k==0) n/=k,ans++;
			else {
				ans+=n-(n/k)*k;
				n=(n/k)*k;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}