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
char s[1005][1005];
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	if (m%2==1){
		puts("YES");
		For(i,1,(m+1)/2) printf("1 2 ");
		puts("");
		return;
	}
	For(i,1,n) For(j,i+1,n)
		if (s[i][j]==s[j][i]){
			puts("YES");
			For(k,1,m/2) printf("%d %d ",i,j);
			printf("%d\n",i);
			return;
		}
	For(i,1,n){
		int v0=-1,v1=-1;
		For(j,1,n) if (j!=i)
			s[i][j]=='a'?v0=j:v1=j;
		if (v0!=-1&&v1!=-1){
			if (m%4==2){
				puts("YES");
				For(k,1,m/4) printf("%d %d %d %d ",v0,i,v1,i);
				printf("%d %d %d\n",v0,i,v1);
				return;
			}
			else{
				puts("YES");
				For(k,1,m/4) printf("%d %d %d %d ",i,v0,i,v1);
				printf("%d\n",i);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}