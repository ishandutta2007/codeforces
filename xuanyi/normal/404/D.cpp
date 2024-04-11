#include <cstdio>
#include <cstring>
#define MOD 1000000007
typedef long long ll;

const int MAXN=1000005;

int n; ll ans,p[MAXN][9];
char s[MAXN];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	p[0][3]=1;
	for (int i=1;i<=n;++i){
		if (s[i]=='?'){
			p[i][0]=p[i-1][0]+p[i-1][5]+p[i-1][8];
			p[i][1]=p[i-1][0]+p[i-1][5]+p[i-1][8];
			p[i][2]=p[i-1][0]+p[i-1][5]+p[i-1][8];
			p[i][3]=p[i-1][3]+p[i-1][6];
			p[i][4]=p[i-1][3]+p[i-1][6];
			p[i][5]=p[i-1][4]+p[i-1][7];
			p[i][6]=p[i-1][1];
			p[i][7]=p[i-1][1];
			p[i][8]=p[i-1][2];
			if (i==1) p[1][0]=1;
		} else if (s[i]=='*'){
			p[i][0]=p[i-1][0]+p[i-1][5]+p[i-1][8];
			p[i][5]=p[i-1][4]+p[i-1][7];
			p[i][8]=p[i-1][2];
			if (i==1) p[1][0]=1;
		} else if (s[i]=='0'){
			p[i][3]=p[i-1][3]+p[i-1][6];
			p[i][6]=p[i-1][1];
		} else if (s[i]=='1'){
			p[i][1]=p[i-1][0]+p[i-1][5]+p[i-1][8];
			p[i][4]=p[i-1][3]+p[i-1][6];
			p[i][7]=p[i-1][1];
		} else if (s[i]=='2'){
			p[i][2]=p[i-1][0]+p[i-1][5]+p[i-1][8];
		}
		for (int j=0;j<9;++j) while (p[i][j]>=MOD) p[i][j]-=MOD;
//		for (int j=0;j<9;++j) fprintf(stderr,"p[%d][%d]=%lld\n",i,j,p[i][j]);
	}
	ans=p[n][0]+p[n][1]+p[n][3]+p[n][5]+p[n][6]+p[n][8];
	printf("%I64d\n",ans%MOD);
	return 0;
}