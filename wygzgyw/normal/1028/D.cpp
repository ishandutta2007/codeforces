#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=(2e9);
const int mod=(1e9)+7;
int n,x,l,r;
ll ans,cnt;
set<int>S;
set<int>::iterator it;
char s[10];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	S.insert(INF); S.insert(-INF);
	ans=cnt=1;
	l=-INF; r=INF;
	while (n--) {
		scanf("%s",s); read(x);
		if (s[1]=='D') {
			S.insert(x);
			if (l<=x&&x<=r) cnt++;
		} else {
			if (x<l||x>r) { ans=0; break; }
			if (x!=l&&x!=r) ans*=2,ans%=mod;
			S.erase(x);
			it=S.lower_bound(x); 
			r=*it;
			l=*(--it);
			cnt=1;
		}
	}
	printf("%lld\n",(ll)ans*cnt%mod);
	return 0;
}