#include"bits/stdc++.h"
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,r,l) for(int i=r;i>=l;i--)
#define mp make_pair
typedef long long ll;
using namespace std;
const int N=505;
char s[N][N];int n,m,mxx,mnx,mxy,mny;
int main(){
	scanf("%d%d\n",&n,&m);mnx=mny=2333;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='X'){
				mnx=min(mnx,i);mny=min(mny,j);
				mxx=max(mxx,i);mxy=max(mxy,j);
			}
		}
	}
	for(int i=mnx;i<=mxx;i++)
		for(int j=mny;j<=mxy;j++)
			if(s[i][j]!='X'){puts("NO");return 0;}
	puts("YES");
	return 0;
}