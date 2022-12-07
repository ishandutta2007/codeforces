#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,x,a[100005],s[100005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) s[i]=0;
	For(i,1,n) scanf("%d",&x),++s[x];
	int s1=0,s2=0;
	For(i,1,n)
		if (s[i]>s1) s1=s[i],s2=1;
		else if (s[i]==s1) ++s2;
	//cout<<s1<<' '<<s2<<endl;
	assert(s1!=1);
	printf("%d\n",(n-s2)/(s1-1)-1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}