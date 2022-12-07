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
const int N=1005;
char s[N];
int len[N],val[15];
int n,a[N][N],f[N][N];
int rk[N],nrk[N],pos[N],v[N];
void input(int id){
	scanf("%s",s+1);
	len[id]=strlen(s+1);
	reverse(s+1,s+len[id]+1);
	For(i,1,len[id]) a[id][i]=(s[i]=='?'?-1:s[i]-'0');
	//For(i,1,len[id]) cout<<a[id][i]<<' '; cout<<endl; 
}
int main(){
	//freopen("1.in","r",stdin);
	input(0);
	scanf("%d",&n);
	For(i,1,n) input(i);
	For(i,0,9) scanf("%d",&val[i]);
	memset(f,150,sizeof(f));
	f[0][0]=0;
	For(i,1,n) rk[i]=i;
	For(i,1,N-1){
		For(j,1,n) pos[rk[j]]=j;
		For(nov,0,9){
			if (a[0][i]!=nov&&a[0][i]!=-1) continue;
			if (nov==0&&i==len[0]) continue;
			int nork=0,vtr=0;
			For(k,1,n){
				v[k]=a[k][i]+nov;
				if (i>len[k]&&i>len[0]) continue;
				if (v[k]>=10) ++nork,v[k]-=10;
				vtr+=val[v[k]];
			}
			For(lark,0,n){
				if (lark!=0){
					int p=pos[lark];
					if (i<=len[p]||i<=len[0]) vtr-=val[v[p]];
					if ((++v[p])==10) v[p]=0,nork++;
					vtr+=val[v[p]];
				}
				f[i][nork]=max(f[i][nork],f[i-1][lark]+vtr);
			}
		}
		int p=0;
		For(j,1,n) pos[rk[j]]=j;
		Rep(v,9,0) For(j,1,n)
			if (a[pos[j]][i]==v)
				nrk[pos[j]]=++p;
		memcpy(rk,nrk,sizeof(nrk));
	}
	int ans=0;
	For(i,0,n) ans=max(ans,f[N-1][i]);
	printf("%d\n",ans);
}