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
const int N=100005;
int suf[N][27],pre[N][27];
int isuf[N][27],ipre[N][27];
int stl[20][N],str[20][N];
ll Sl[20][N],Sr[20][N];
int lvl[N],L[N],R[N],T[N];
int n,le[N],ri[N],lg[N];
char s[N];
ll ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) s[i]-='a';
	For(i,0,25){
		suf[n][i]=suf[n+1][i]=n+1;
		ipre[0][i]=ipre[1][i]=i;
		isuf[n][i]=isuf[n+1][i]=i;
	}
	For(i,1,n){
		For(j,0,25)
			pre[i+1][j]=pre[i][j];
		pre[i+1][s[i]]=i;
		ipre[i+1][0]=s[i];
		int tmp=1;
		For(j,0,25)
			if (ipre[i][j]!=s[i])
				ipre[i+1][tmp++]=ipre[i][j];
	}
	Rep(i,n,1){
		For(j,0,25)
			suf[i-1][j]=suf[i][j];
		suf[i-1][s[i]]=i;
		isuf[i-1][0]=s[i];
		int tmp=1;
		For(j,0,25)
			if (isuf[i][j]!=s[i])
				isuf[i-1][tmp++]=isuf[i][j];
	}
	For(i,1,n){
		L[i]=le[i]=max(1,pre[i][s[i]]);
		R[i]=ri[i]=min(n,suf[i][s[i]]);
		stl[0][i]=n; str[0][i]=1;
		lvl[i]=0; T[i]=1; ans+=n-1;
		For(j,0,25) lvl[i]+=(suf[L[i]-1][j]<=R[i]);
	}
	ri[0]=n;
	le[n+1]=1;
	For(i,2,n) lg[i]=lg[i/2]+1;
	cerr<<clock()<<endl;
	For(i,1,26){
		For(j,1,n){
			Sl[0][j]=j-1; Sr[0][j]=n-j;
			stl[0][j]=min(stl[0][j],le[suf[j-1][isuf[j-1][i-1]]]);
			str[0][j]=max(str[0][j],ri[pre[j+1][ipre[j+1][i-1]]]);
		}
		For(j,1,lg[n/i]) For(k,1,n){
			stl[j][k]=stl[j-1][stl[j-1][k]];
			str[j][k]=str[j-1][str[j-1][k]];
			Sl[j][k]=Sl[j-1][k]+Sl[j-1][stl[j-1][k]];
			Sr[j][k]=Sr[j-1][k]+Sr[j-1][str[j-1][k]];
		}
		For(j,1,n) if (lvl[j]==i){
			int pl=L[j],pr=R[j];
			int liml=(i==26?0:pre[pr+1][ipre[pr+1][i]]);
			int limr=(i==26?n+1:suf[pl-1][isuf[pl-1][i]]);
			Rep(k,lg[n/i],0)
				if (stl[k][pl]>liml&&str[k][pr]<limr){
					ans+=Sl[k][pl]+Sr[k][pr];
					pl=stl[k][pl];
					pr=str[k][pr];
				}
			ans+=pl-1+n-pr;
			L[j]=pl=stl[0][pl];
			R[j]=pr=str[0][pr];
			lvl[j]=0;
			For(k,0,25)
				lvl[j]+=(suf[pl-1][k]<=pr);
		}
	}
	printf("%lld\n",ans);
}