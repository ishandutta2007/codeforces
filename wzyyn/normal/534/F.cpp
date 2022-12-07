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
int n,m,L1[35],L2[35];
vector<int> vec[35];
int f[22][17000][32];
int g[22][17000][32];
int tr[32][32],P[32];
char ans[55][55];
void init(){
	For(i,0,(1<<n)-1){
		int sum=0;
		For(j,0,n-1) if ((i&(1<<j))==(1<<j)) sum++;
		For(j,0,n-2) if ((i&(3<<j))==(3<<j)) sum--;
		vec[sum].PB(i);
	}
	P[0]=1;
	For(i,1,n) P[i]=1ll*P[i-1]*7;
	For(i,0,(1<<n)-1) For(j,0,(1<<n)-1)
		For(k,0,n-1) if ((j&(1<<k))&&!(i&(1<<k)))
			tr[i][j]+=P[k];
}
void construct(int p,int s1,int s2,int la){
	For(i,0,n-1) For(j,1,m) ans[i][j]='.';
	for (int pp=p,S=s1,st=la;pp;pp--){
		For(i,0,n-1) if (st&(1<<i)) ans[i][pp]='*';
		int tmp=f[pp][S][st];
		S-=tr[tmp][st]; st=tmp;
	}
	for (int pp=p,S=s2,st=la;pp<=m;pp++){
		For(i,0,n-1) if (st&(1<<i)) ans[i][pp]='*';
		int tmp=g[pp][S][st];
		S-=tr[tmp][st]; st=tmp;
	}
	For(i,0,n-1) printf("%s\n",ans[i]+1);
	exit(0);
}
int main(){
	scanf("%d%d",&n,&m); init();
	For(i,1,n) scanf("%d",&L1[i]);
	For(i,1,m) scanf("%d",&L2[i]);
	int mid=(m+1)/2;
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	f[0][0][0]=0; g[m+1][0][0]=0;
	For(i,1,mid) For(j,0,P[n]-1)
		for (auto la:vec[L2[i-1]]) if (f[i-1][j][la]!=-1)
			for (auto no:vec[L2[i]])
				f[i][j+tr[la][no]][no]=la;
	Rep(i,m,mid) For(j,0,P[n]-1)
		for (auto la:vec[L2[i+1]]) if (g[i+1][j][la]!=-1) 
			for (auto no:vec[L2[i]])
				g[i][j+tr[la][no]][no]=la;
	//cout<<f[1][57][7]<<endl;
	//cout<<f[2][57][4]<<' '<<P[n]<<endl;
	For(j,0,P[n]-1) for (auto la:vec[L2[mid]])
		if (f[mid][j][la]!=-1){
			int flg=0,now=0;
			For(k,0,n-1){
				int v=j/P[k]%7;
				v=L1[k+1]+((la>>k)&1)-v;
				if (v>=0&&v<=6) now+=P[k]*v;
				else flg=1;
			}
			//cout<<j<<' '<<la<<' '<<now<<endl;
			if (flg==1||g[mid][now][la]==-1) continue;//break;
			construct(mid,j,now,la);
		}
}