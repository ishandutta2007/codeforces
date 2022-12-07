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
const int N=1000005;
int n,m,k;
char s1[25],s2[25];
int x[N],y[N],q1[N],q2[N];
int mn[1<<20|5][22],p[25];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s1+1,s2+1);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,k) p[i]=i;
	//cerr<<233<<endl;
	Rep(i,n,0){
		For(j,1,k) if (s1[j]=='1') q1[i]|=1<<(p[j]-1);
		For(j,1,k) if (s2[j]=='1') q2[i]|=1<<(p[j]-1);
		//cout<<q1[i]<<' '<<q2[i]<<endl;
		swap(p[x[i]],p[y[i]]);
	}
	memset(mn,30,sizeof(mn));
	For(i,0,n) mn[q1[i]][0]=min(mn[q1[i]][0],i);
	int ans=k+1,al=0,ar=0;
	For(i,0,k){
		For(j,0,(1<<k)-1) if (mn[j][i]<=n+1) For(p,0,k-1)
			mn[j^(1<<p)][i+1]=min(mn[j^(1<<p)][i+1],mn[j][i]);
		For(j,0,n)
			if (mn[q2[j]][i]<=j-m){
				ans=k-i,al=mn[q2[j]][i],ar=j;
				break;
			}
		if (ans!=k+1)
			break;
	}
	printf("%d\n%d %d\n",ans,al+1,ar);
	//cao
}