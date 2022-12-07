#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
char s[N];
int ans,ansl,ansr,n,mnn;
int S[N],f[N][4][6];
int fr1[N][4][6];
int fr2[N][4][6];
void update(int n,int f1,int f2){
	//printf("%d %d %d %d\n",n,f1,f2,f[n][f1][f2]);
	if (!n) return;
	if (fr1[n][f1][f2]!=f1)
		if (!ansr) ansr=n;
	else ansl=n;
	update(n-1,fr1[n][f1][f2],fr2[n][f1][f2]);
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n) S[i]=S[i-1]+(s[i]=='('?1:-1);
	if (S[n]!=0) return puts("0\n1 1"),0;
	For(i,1,n) mnn=min(mnn,S[i]);
	ansl=1,ansr=1;
	For(i,1,n) ans+=(S[i]==mnn);
	memset(f,233,sizeof(f));
	f[0][0][min(5,2+S[0]-mnn)]=0;
	//printf("%d %d %d %d\n",min(5,2+S[0]-mnn),S[1],S[7],S[8]);
	For(i,1,n) For(St,0,3) For(mn,0,5){
		int v=S[i]+(St==2?2:(St==1?-2:0));
		int nmn=min(mn,2+v-mnn);
		int val=(nmn==2+v-mnn)+(nmn==mn?f[i-1][St][mn]:min(0,f[i-1][St][mn]));
		if (val>f[i][St][nmn]){
			f[i][St][nmn]=val;
			fr1[i][St][nmn]=St;
			fr2[i][St][nmn]=mn;
		}
		if (s[i]=='('&&(St&1)){
			val=(nmn==2+v-mnn)+(nmn==mn?f[i-1][St-1][mn]:min(0,f[i-1][St-1][mn]));
			if (val>f[i][St][nmn]){
				f[i][St][nmn]=val;
				fr1[i][St][nmn]=St-1;
				fr2[i][St][nmn]=mn;
			}
		}
		if (s[i]==')'&&(St&2)){
			val=(nmn==2+v-mnn)+(nmn==mn?f[i-1][St-2][mn]:min(0,f[i-1][St-2][mn]));
			if (val>f[i][St][nmn]){
				f[i][St][nmn]=val;
				fr1[i][St][nmn]=St-2;
				fr2[i][St][nmn]=mn;
			}
		}
	}
	For(i,0,4)
		if (f[n][3][i]>ans){
			ans=f[n][3][i];
			ansl=ansr=0;
			update(n,3,i);
			//printf("%d %d\n",ans,i);
		}
	printf("%d\n%d %d\n",ans,ansl,ansr);
}
/*
)(()()(())()
*/