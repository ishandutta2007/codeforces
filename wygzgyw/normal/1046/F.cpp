#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n;
ll a[maxn],x,f,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
    for (int i=1;i<=n;i++)
    	read(a[i]);
    read(x); read(f);
    for (int i=1;i<=n;i++)
    	ans+=(a[i]+f-1)/(x+f)*f;
    printf("%lld\n",ans);
    return 0;
}