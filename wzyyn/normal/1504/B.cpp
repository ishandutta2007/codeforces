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

int n;
char s[300005];
char t[300005];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int la=0,s1=0,s2=0;
	for (int i=1;i<=n;i++){
		s1+=(s[i]=='0'?1:-1);
		s2+=(s[i]=='0'?1:-1);
		if ((s1==0)!=(s2==0))
			return puts("NO"),void(0);
		if (s1==0){
			for (int j=la+1;j<=i;j++)
				if (s[i]^s[j]^t[i]^t[j])
					return puts("NO"),void(0);
			la=i;
		}
	}
	for (int i=la+1;i<=n;i++)
		if (s[i]!=t[i])
			return puts("NO"),void(0);
	puts("YES");	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}