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

const int N=400005;

int n,ans;
int mat[N],f[N];
int mn[N],mx[N];
void solve(int l,int r){
	
	static int v[2],s[2][2];
	memset(v,30,sizeof(v));
	memset(s,0,sizeof(s));
	
	for (int i=l;i<=r;i++){
		int p=(v[1]<v[0]);
		if (v[p]>=mat[i]);
		else if (v[p^1]>=mat[i]) p^=1;
		else{
			puts("-1");
			exit(0);
		}
		v[p]=mat[i];
		++s[p][f[i]];
	}
	
	ans+=min(s[0][1]+s[1][0],s[0][0]+s[1][1]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<=n&&y<=n)
			return puts("-1"),0;
		mat[x]=y; f[x]=0;
		mat[y]=x; f[x]=1;
	}
	mn[0]=1<<30; mx[n+1]=0;
	for (int i=1;i<=n;i++)
		mn[i]=min(mn[i-1],mat[i]);
	for (int i=n;i>=1;i--)
		mx[i]=max(mx[i+1],mat[i]);
		
	int la=0;
	for (int i=1;i<=n;i++)
		if (mn[i]>mx[i+1])
			solve(la+1,i),la=i;
	printf("%d\n",ans);
}