#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int px,py,a[5];
char s[100005];
void solve(){
	scanf("%d%d%s",&px,&py,s+1);
	a[0]=a[1]=a[2]=a[3]=0;
	for (int i=1;s[i];++i){
		if (s[i]=='R') ++a[0];
		if (s[i]=='L') ++a[1];
		if (s[i]=='U') ++a[2];
		if (s[i]=='D') ++a[3];
	}
	if (px<-a[1]||px>a[0]||py<-a[3]||py>a[2]) puts("NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}