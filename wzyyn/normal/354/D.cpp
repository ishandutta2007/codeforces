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
const int N=805;
int n,k;
vector<int> vec[100005];
int f[2][N],sum[100005];
int main(){
	scanf("%d%d",&n,&k);
	int m=(int)(sqrt(6*k)+2);
	For(i,1,k){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[n-y+1].PB(n-x+1);
	}
	memset(f,30,sizeof(f));
	f[0][0]=0;
	For(i,1,n){
		int now=i&1,pre=now^1;
		memset(f[now],30,sizeof(f[now]));
		For(j,1,m) sum[j]=1;
		for (auto j:vec[i]) sum[j]=-2;
		For(j,1,m) sum[j]+=sum[j-1];
		int tmp=1<<30;
		Rep(j,m,0){
			tmp=min(tmp,f[pre][j]);
			f[now][j]=min(f[now][j],tmp+sum[j]+(j==0?0:2)+j*(j-1)/2);
			if (j) f[now][j]=min(f[now][j],f[pre][j-1]+sum[j]+(j==1?2:0));
			//cout<<i<<' '<<j<<' '<<f[now][j]<<endl;
		}
	}
	int ans=0;
	For(i,0,m) ans=min(ans,f[n&1][i]);
	printf("%d\n",3*k+ans);
}

/*
.
.*
*..
..*.
**..*
...*..
.****..
*/