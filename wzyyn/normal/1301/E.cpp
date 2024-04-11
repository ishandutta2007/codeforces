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

const int N=505;
int LG[N],n,m,Q;
int st[N][N][9];
int stt[N][N][9][9];
char s[N][N];
int check(int x,int y,int l){
	int k=LG[l];
	char a=st[x][y][k];
	char b=st[x+l-(1<<k)][y][k];
	char c=st[x][y+l-(1<<k)][k];
	char d=st[x+l-(1<<k)][y+l-(1<<k)][k];
	return a==b&&a==c&&a==d?a:-1;
}
int query(int x1,int y1,int x2,int y2){
	int l1=LG[x2-x1+1];
	int l2=LG[y2-y1+1];
	int a=stt[x1][y1][l1][l2];
	int b=stt[x2-(1<<l1)+1][y1][l1][l2];
	int c=stt[x1][y2-(1<<l2)+1][l1][l2];
	int d=stt[x2-(1<<l1)+1][y2-(1<<l2)+1][l1][l2];
	return max(max(a,b),max(c,d));
}
int main(){
	For(i,2,N-1) LG[i]=LG[i/2]+1;
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) st[i][j][0]=s[i][j];
	For(i,1,8) For(j,1,n-(1<<i)+1) For(k,1,m-(1<<i)+1){
		char a=st[j][k][i-1];
		char b=st[j+(1<<(i-1))][k][i-1];
		char c=st[j][k+(1<<(i-1))][i-1];
		char d=st[j+(1<<(i-1))][k+(1<<(i-1))][i-1];
		st[j][k][i]=(a==b&&a==c&&a==d?a:-1);
	}
	For(i,1,n-1) For(j,1,m-1)
		if (s[i][j]=='R'&&s[i][j+1]=='G')
			if (s[i+1][j]=='Y'&&s[i+1][j+1]=='B'){
				int l=1,r=min(min(i,n-i+1),min(j,m-j+1)),ans;
				while (l<=r){
					int mid=(l+r)/2;
					if (check(i-mid+1,j-mid+1,mid)!=-1&&
						check(i+1,j-mid+1,mid)!=-1&&
						check(i-mid+1,j+1,mid)!=-1&&
						check(i+1,j+1,mid)!=-1)
							ans=mid,l=mid+1;
					else r=mid-1;
				}
				stt[i][j][0][0]=ans;
			}
	For(v1,1,8) For(i,1,n-(1<<v1)+1) For(j,1,m){
		int a=stt[i][j][v1-1][0];
		int b=stt[i+(1<<(v1-1))][j][v1-1][0];
		stt[i][j][v1][0]=max(a,b);
	}
	For(v1,0,8) For(v2,1,8) For(i,1,n-(1<<v1)+1) For(j,1,m-(1<<v2)+1){
		int a=stt[i][j][v1][v2-1];
		int b=stt[i][j+(1<<(v2-1))][v1][v2-1];
		stt[i][j][v1][v2]=max(a,b);
	}
	while (Q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int l=1,r=min(x2-x1+1,y2-y1+1)/2,ans=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (query(x1+mid-1,y1+mid-1,x2-mid,y2-mid)>=mid)
				ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",4*ans*ans);
	}
}