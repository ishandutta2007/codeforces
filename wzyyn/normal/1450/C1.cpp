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

char s[305][305];
int n,s1[3],s2[3];
void solve(){
	For(i,0,2) s1[i]=s2[i]=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s[i]+1);
		For(j,1,n){
			if (s[i][j]=='X') ++s1[(i+j)%3];
			if (s[i][j]=='O') ++s2[(i+j)%3];
		}
	}
	int p=0;
	For(i,0,2) if (s1[p]+s2[(p+1)%3]>=s1[i]+s2[(i+1)%3]) p=i;
	For(i,1,n) For(j,1,n){
		if ((i+j)%3==p&&s[i][j]=='X') s[i][j]='O';
		if ((i+j)%3==(p+1)%3&&s[i][j]=='O') s[i][j]='X';
	}
	For(i,1,n) printf("%s\n",s[i]+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}