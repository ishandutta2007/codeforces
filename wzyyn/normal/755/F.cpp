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
int n,k,a[N],b[N],vis[N];
bitset<N> f;
void ins_loop(int x){
	int cnt=0;
	for (;!vis[x];)
		++cnt,vis[x]=1,x=a[x];
	++b[cnt];
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (!vis[i]) ins_loop(i);
	int s1=0,s2=0; f[0]=1;
	For(i,1,n) if (b[i]){
		int j=b[i],k=1;
		s1+=b[i]*(i/2);
		s2+=b[i]*(i%2);
		for (;k<j;j-=k,k*=2) f|=f<<(k*i);
		f|=f<<(j*i);
	}
	//cout<<s1<<' '<<s2<<endl;
	int ans1=min(n,k+min(k,s1));
	int ans2=k+(!f[k]);
	printf("%d %d\n",ans2,ans1);
}