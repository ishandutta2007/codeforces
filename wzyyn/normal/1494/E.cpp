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
int s1,s2,n,Q;
map<pii,char> mp;
int main(){
	scanf("%d%d",&n,&Q);
	while (Q--){
		char s[10];
		int x,y;
		scanf("%s",s+1);
		if (s[1]=='+'){
			scanf("%d%d%s",&x,&y,s+1);
			mp[pii(x,y)]=s[1];
			if (mp[pii(y,x)]!=0) ++s1;
			if (mp[pii(y,x)]==mp[pii(x,y)]) ++s2;
		}
		else if (s[1]=='-'){
			scanf("%d%d",&x,&y);
			if (mp[pii(y,x)]!=0) --s1;
			if (mp[pii(y,x)]==mp[pii(x,y)]) --s2;
			mp[pii(x,y)]=0;
		}
		else{
			scanf("%d",&x);
			if (x%2==0) puts(s2?"YES":"NO");
			else puts(s1?"YES":"NO");
		}
	}
}