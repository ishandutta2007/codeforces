#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
char s[505][505];
int ans[505][505];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[i][j]=0;
		if(n<=2){
			for(int i=1;i<=m;i++) ans[1][i]=1;
			if(n==2) for(int i=1;i<=m;i++) if(s[2][i]=='X') ans[2][i]=1;
		}
		else if(m<=2){
			for(int i=1;i<=n;i++) ans[i][1]=1;
			if(m==2) for(int i=1;i<=n;i++) if(s[i][2]=='X') ans[i][2]=1;
		}
		else if(n%3==0){
			for(int i=2;i<=n;i+=3) for(int j=1;j<=m;j++) ans[i][j]=1;
			for(int i=1;i<=n;i++) ans[i][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(s[i][j]!='X') continue;
					if(i%3==2);
					else if(i%3==1){
						if(j==1);
						else if(j==2) ans[i+1][2]=0,ans[i][2]=ans[i][3]=1;
						else if(j==4&&s[i][j-2]=='X') ans[i+1][3]=0,ans[i][4]=1;
						else ans[i][j]=1;
					}
					else if(i%3==0){
						if(j==1);
						else if(j==2) ans[i-1][2]=0,ans[i][2]=ans[i][3]=1;
						else if(j==4&&s[i][j-2]=='X') ans[i-1][3]=0,ans[i][4]=1;
						else ans[i][j]=1;
					}
				}
			}
			for(int i=2;i<=n;i+=3) if(ans[i-1][2]&&ans[i+1][2]&&(m<4||!(ans[i-1][4]^ans[i+1][4]))) ans[i][1]=0;
			for(int i=1;i<=n;i+=3) if(ans[i][3]&&!ans[i+1][3]) ans[i][2]=1;
			for(int i=3;i<=n;i+=3) if(ans[i][3]&&!ans[i-1][3]) ans[i][2]=1;
		}
		else{
			for(int i=1;i<=n;i+=3) for(int j=1;j<=m;j++) ans[i][j]=1;
			for(int i=1;i<=n;i++) ans[i][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(s[i][j]!='X') continue;
					if(i%3==1);
					else if(i%3==0){
						if(j==1);
						else if(j==2) ans[i+1][2]=0,ans[i][2]=ans[i][3]=1;
						else if(j==4&&s[i][j-2]=='X') ans[i+1][3]=0,ans[i][4]=1;
						else ans[i][j]=1;
					}
					else if(i%3==2){
						if(j==1);
						else if(j==2) ans[i-1][2]=0,ans[i][2]=ans[i][3]=1;
						else if(j==4&&s[i][j-2]=='X') ans[i-1][3]=0,ans[i][4]=1;
						else ans[i][j]=1;
					}
				}
			}
			for(int i=4;i<n;i+=3) if(ans[i-1][2]&&ans[i+1][2]&&(m<4||!(ans[i-1][4]^ans[i+1][4]))) ans[i][1]=0;
			for(int i=3;i<=n;i+=3) if(ans[i][3]&&!ans[i+1][3]) ans[i][2]=1;
			for(int i=2;i<=n;i+=3) if(ans[i][3]&&!ans[i-1][3]) ans[i][2]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) putchar(ans[i][j]==1?'X':'.');
			puts("");
		}
	}
	return 0;
}