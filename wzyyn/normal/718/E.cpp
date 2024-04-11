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
const int N=100005;
const int inf=1<<29;
char s[N];
int dis[8][N],D[8][8];
int q[N],sum[8][1<<8],st[N],n;
int func[8][8][1<<8][1<<8];
vector<int> v[8];
ll ans[17];
void SSSP(int c){
	static int vis[10];
	For(i,0,7) vis[i]=(i==c);
	For(i,1,n) dis[c][i]=inf;
	int h=0,t=0;
	for (auto i:v[c]) q[++t]=i,dis[c][i]=0;
	//cout<<c<<' '<<t<<endl;
	while (h!=t){
		int x=q[++h];
		if (x!=1&&dis[c][x-1]==inf)
			dis[c][x-1]=dis[c][x]+1,q[++t]=x-1;
		if (x!=n&&dis[c][x+1]==inf)
			dis[c][x+1]=dis[c][x]+1,q[++t]=x+1;
		if (!vis[s[x]-'a']){
			vis[s[x]-'a']=1;
			for (auto i:v[s[x]-'a'])
				if (dis[c][i]==inf)
					dis[c][i]=dis[c][x]+1,q[++t]=i;
		}
	}
}
void Mn(int &x,int y){
	x>y?x=y:233;
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,0,7) For(j,1,n) if (s[j]=='a'+i) v[i].PB(j);
	For(i,0,7) SSSP(i);
	//cout<<233<<endl;
	For(i,0,7) For(j,0,7) D[i][j]=inf;
	For(i,0,7) For(j,1,n) Mn(D[i][s[j]-'a'],dis[i][j]);
	For(i,0,7) For(j,1,n) st[j]+=(dis[i][j]-D[i][s[j]-'a'])<<i;
	For(i,0,7) For(j,0,7)
		For(s1,0,255) For(s2,0,255){
			int val=16;
			For(k,0,7) Mn(val,D[i][k]+D[k][j]+1+((s1>>k)&1)+((s2>>k)&1));
			func[i][j][s1][s2]=val;
		}
	//cout<<233<<endl;
	For(i,1,n) For(j,max(i-15,1),i-1){
		int val=i-j;
		For(k,0,7) Mn(val,dis[k][i]+dis[k][j]+1);
		//cout<<i<<' '<<j<<' '<<val<<endl;
		++ans[val];
	}
	//cout<<233<<endl;
	For(i,1,n){
		//cout<<st[i]<<endl; 
		if (i-16>=1) ++sum[s[i-16]-'a'][st[i-16]];
		For(j,0,7) For(k,0,255)
			ans[func[s[i]-'a'][j][st[i]][k]]+=sum[j][k];
	}
	//cout<<233<<endl;
	int p=15;
	for (;!ans[p];--p);
	printf("%d %lld\n",p,ans[p]);
}