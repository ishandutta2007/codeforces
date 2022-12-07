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
const int N=200005;
set<int> S;
char s[N];
int n,ans[N];
pii op[N];
int main(){
	scanf("%d",&n);
	For(i,1,2*n){
		scanf("%s",s+1);
		op[i].fi=s[1];
		if (s[1]=='-')
			scanf("%d",&op[i].se);
	}
	int p=n,GG=0;
	Rep(i,2*n,1)
		if (op[i].fi=='-'){
			if (!S.empty()&&op[i].se>*S.begin()){
				GG=1;
				break;
			}
			S.insert(op[i].se);
		}
		else{
			if (S.empty()){
				GG=1;
				break;
			}
			ans[p--]=*S.begin();
			S.erase(S.begin());
		}
	if (GG)
		puts("NO");
	else{
		puts("YES");
		For(i,1,n) printf("%d ",ans[i]);
	}
}