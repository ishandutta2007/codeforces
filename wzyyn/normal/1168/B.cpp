#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
char s[300005];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),l=(1<<30);
	ll ans=0;
	For(i,1,n){
		++l;
		For(j,1,min(min(i,l),100)/2)
			if (s[i]==s[i-j]&&s[i-j]==s[i-j-j])
				l=2*j;
		if (l<(1<<30))
			ans+=i-l;
	}
	printf("%lld\n",ans);
}
/*
011011  X
0110100 X
0110011
*/