#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
int n,m,ss[25];
char s[100005];
int S[25][25];
int f[1<<20];
int cnt[1<<20];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	For(i,1,n-1){
		int c1=s[i]-'a',c2=s[i+1]-'a';
		if (c1>c2) swap(c1,c2);
		if (c1!=c2) ++S[c1][c2],++ss[c1],++ss[c2];
	}
	memset(f,60,sizeof(f));
	f[0]=0;
	For(i,0,(1<<m)-1){
		cnt[i]=cnt[i/2]+(i&1);
		For(j,0,m-1) if (!(i&(1<<j))){
			int sum=0;
			For(k,0,m-1) if (i&(1<<k)) sum+=S[j][k]+S[k][j];
			//printf("%d %d %d %d %d\n",i,f[i],j,sum,ss[j]);
			f[i|(1<<j)]=min(f[i|(1<<j)],f[i]+(2*sum-ss[j])*(cnt[i]+1));
		}
		//printf("%d ",f[i]);
	}
	printf("%d\n",f[(1<<m)-1]);
}