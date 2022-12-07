#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,cnt[505];
char s[505][105];
int main(){
	scanf("%d",&n);
	scanf("%s",s[0]+1);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if (s[0][i]=='1') ++cnt[0];
		For(j,1,500){
			s[j][i]=s[j-1][i];
			if (j>=y&&(j-y)%x==0)
				s[j][i]^=1;
			if (s[j][i]=='1') ++cnt[j];
		}
	}
	int ans=0;
	For(i,0,500)
		ans=max(ans,cnt[i]);
	printf("%d\n",ans);
}