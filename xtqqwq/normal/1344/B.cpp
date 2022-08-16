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
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int a[1005][1005],sum1[1005][1005],sum2[1005][1005];
pii q[1000005];
bool vis[1005][1005];
char s[1005][1005];

void bfs(int i,int j){
	int front=0,rear=0;
	q[rear++]=mp(i,j);
	vis[i][j]=1;
	while(front<rear){
		pii t=q[front++];
		for(int i=0;i<4;i++){
			int dx=t.fi+dir[i][0],dy=t.se+dir[i][1];
			if(dx<1||dx>n||dy<1||dy>m||vis[dx][dy]||s[dx][dy]=='.') continue;
			vis[dx][dy]=1;
			q[rear++]=mp(dx,dy);
		}
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=s[i][j]=='#';
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) sum1[i][j]=sum1[i][j-1]+a[i][j],sum2[i][j]=sum2[i-1][j]+a[i][j];
	bool fl=1,a1=0,a2=0,hv1=0,hv2=0;
	for(int i=1;i<=n;i++){
		bool fl1=0,fl2=0;
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'&&fl2) fl=0;
			if(s[i][j]=='#') fl1=1;
			if(fl1&&s[i][j]=='.') fl2=1;
		}
		if(!fl1) hv1=1;
		if(sum1[i][m]==0) a1=1;
	}
	for(int i=1;i<=m;i++){
		bool fl1=0,fl2=0,fl3=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='#'&&fl2) fl=0;
			if(s[j][i]=='#') fl1=1;
			if(fl1&&s[j][i]=='.') fl2=1;
		}
		if(!fl1) hv2=1;
		if(sum2[n][i]==0) a2=1;
	}
//	cout<<"test "<<a1<<' '<<a2<<' '<<hv1<<' '<<hv2<<endl;
	if(a1&&!hv2) fl=0;
	if(a2&&!hv1) fl=0;
	if(!fl) return printf("-1\n"),0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&s[i][j]=='#'){
				cnt++;
				bfs(i,j);
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}