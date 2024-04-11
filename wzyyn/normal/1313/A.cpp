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

void solve(){
	int a,b,c,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	For(i,0,127){
		int s1=0,s2=0,s3=0,S=0;
		For(j,1,7) if (i&(1<<(j-1)))
			s1+=j%2,s2+=j/2%2,s3+=j/4,S++;
		if (s1<=a&&s2<=b&&s3<=c) ans=max(ans,S);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}