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
char s[200005];
int q[200005],n;
int rem[200005];
bool check(int v){
	int p=1;
	For(i,1,*q) rem[i]=q[i]-(i<=v);
	For(i,1,v-1){
		p=max(p,i);
		for (;p<=*q&&!rem[p];++p);
		if (p>*q) return 0;
		--rem[p];
	}
	return 1;
}
void solve(){
	scanf("%d\n%s",&n,s+1);
	//n=strlen(s+1);
	q[0]=1; q[1]=1;
	For(i,2,n)
		if (s[i]==s[i-1])
			++q[*q];
		else q[++*q]=1;
	//For(i,1,*q) cout<<q[i]<<endl;
	int l=1,r=*q,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}