#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
bool chkmin(int &x,int y){return ((x>y)?(x=y,1):0);}
bool chkmax(int &x,int y){return ((x<y)?(x=y,1):0);}
int n;char s[82];
int pv[82],sv[82],pvcnt=0;//'V'
int pk[82],sk[82],pkcnt=0;//'K'
int po[82],so[82],pocnt=0;//others
int dp[82][82][82][3];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		sk[i]=sk[i-1];sv[i]=sv[i-1];so[i]=so[i-1];
		if(s[i]=='V') pv[++pvcnt]=i,sv[i]++;
		else if(s[i]=='K') pk[++pkcnt]=i,sk[i]++;
		else po[++pocnt]=i,so[i]++;
	}
	memset(dp,63,sizeof(dp));
	dp[0][0][0][0]=0;
	for(int o=0;o<=pocnt;o++) for(int v=0;v<=pvcnt;v++) for(int k=0;k<=pkcnt;k++){
		for(int f=0;f<2;f++){
			if(o!=pocnt) chkmin(dp[o+1][v][k][0],dp[o][v][k][f]+max(o-so[po[o+1]-1],0)+max(v-sv[po[o+1]-1],0)+max(k-sk[po[o+1]-1],0));
			if(v!=pvcnt) chkmin(dp[o][v+1][k][1],dp[o][v][k][f]+max(o-so[pv[v+1]-1],0)+max(v-sv[pv[v+1]-1],0)+max(k-sk[pv[v+1]-1],0));
			if(k!=pkcnt&&!f) chkmin(dp[o][v][k+1][0],dp[o][v][k][f]+max(o-so[pk[k+1]-1],0)+max(v-sv[pk[k+1]-1],0)+max(k-sk[pk[k+1]-1],0));
		}
	}
	printf("%d\n",min(dp[pocnt][pvcnt][pkcnt][0],dp[pocnt][pvcnt][pkcnt][1]));
	return 0;
}
/*
80
VKVKVKVKAAVKVKVKVKAAVKVKVKVKAAVKVKVKVKAAVKVKVKVKAAVKVKVKVKAAVKVKVKVKAAVKVKVKVKAA
*/