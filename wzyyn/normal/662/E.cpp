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
const int N=5005,M=95;
int n,T[N][5],fl[N][5];
int PP[5],GG[5],ans;
int f[M][M][M];
int g[M][M][M];
void UPD(int &x,int y){
	x<y?x=y:233;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,3){
		scanf("%d",&T[i][j]);
		if (T[i][j]==0) T[i][j]=250;
		else{
			++PP[j];
			if (T[i][j]<0){
				++GG[j]; fl[i][j]=1;
				T[i][j]*=-1;
			}
		}
		T[i][j]=250-T[i][j];
	}
	if (GG[1]+GG[2]+GG[3]>=90)
		return puts("1"),0;
	const int P[]={0,3000,2500,2000,1500,1000,500};
	const int lim[]={-1,n/32,n/16,n/8,n/4,n/2,n};
	For(a,1,6) if (PP[1]>lim[a-1]&&PP[1]-GG[1]<=lim[a])
		For(b,1,6) if (PP[2]>lim[b-1]&&PP[2]-GG[2]<=lim[b])
			For(c,1,6) if (PP[3]>lim[c-1]&&PP[3]-GG[3]<=lim[c]){
				int p=P[a]*T[1][1]+P[b]*T[1][2]+P[c]*T[1][3];
				int la=min(GG[1],PP[1]-lim[a-1]-1),sa=0;
				int lb=min(GG[2],PP[2]-lim[b-1]-1),sb=0;
				int lc=min(GG[3],PP[3]-lim[c-1]-1),sc=0;
				//cout<<la<<' '<<lb<<' '<<lc<<endl;
				p+=(la+lb+lc)*250*100;
				int stk=0;
				memset(f,0,sizeof(f));
				memset(g,0,sizeof(g));
				For(i,2,n){
					int va=P[a]*T[i][1];
					int vb=P[b]*T[i][2];
					int vc=P[c]*T[i][3];
					//cout<<(va+vb+vc)/250<<endl;
					if (!fl[i][1]&&!fl[i][2]&&!fl[i][3]){
						stk+=(p>=(va+vb+vc));
						//cout<<stk<<endl;
						continue;
					}
					For(Sa,0,sa) For(Sb,0,sb) For(Sc,0,sc){
						UPD(g[Sa][Sb][Sc],f[Sa][Sb][Sc]+(p>=(va+vb+vc)));
						if (fl[i][1]) UPD(g[Sa+1][Sb][Sc],f[Sa][Sb][Sc]+(p>=(vb+vc)));
						if (fl[i][2]) UPD(g[Sa][Sb+1][Sc],f[Sa][Sb][Sc]+(p>=(va+vc)));
						if (fl[i][3]) UPD(g[Sa][Sb][Sc+1],f[Sa][Sb][Sc]+(p>=(va+vb)));
						if (fl[i][1]&&fl[i][2]) UPD(g[Sa+1][Sb+1][Sc],f[Sa][Sb][Sc]+(p>=vc));
						if (fl[i][1]&&fl[i][3]) UPD(g[Sa+1][Sb][Sc+1],f[Sa][Sb][Sc]+(p>=vb));
						if (fl[i][2]&&fl[i][3]) UPD(g[Sa][Sb+1][Sc+1],f[Sa][Sb][Sc]+(p>=va));
						if (fl[i][1]&&fl[i][2]&&fl[i][3]) UPD(g[Sa+1][Sb+1][Sc+1],f[Sa][Sb][Sc]+(p>=0));
					}
					sa=min(sa+fl[i][1],la);
					sb=min(sb+fl[i][2],lb);
					sc=min(sc+fl[i][3],lc);
					For(Sa,0,sa) For(Sb,0,sb) For(Sc,0,sc){
						f[Sa][Sb][Sc]=g[Sa][Sb][Sc];
						g[Sa][Sb][Sc]=0;
					}
				}
				//cout<<a<<' '<<b<<' '<<c<<' '<<p/250<<endl;
				//cout<<stk<<' '<<f[la][lb][lc]<<endl;
				ans=max(ans,f[la][lb][lc]+stk);
			}
	printf("%d\n",n-ans);
}