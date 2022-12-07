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
void solve(){
	int s1=0,s2=0,ss=0;
	scanf("%s",s+1);
	for (int i=1;s[i];++i)
		if (s[i]=='(') ++s1;
		else if (s[i]=='[') ++s2;
		else if (s[i]==')'){
			if (s1) --s1,++ss;
		}
		else{
			if (s2) --s2,++ss;
		}
	cout<<ss<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}