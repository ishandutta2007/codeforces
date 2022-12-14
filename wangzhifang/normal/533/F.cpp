#include <cstdio>
#include <cstring>
#define max_k 26
#define max_n 200000
#define bas 2333
#define k 26
using namespace std;
typedef unsigned uint;
uint b[max_k+1],pwb[max_n+1]/*power of b*/,pos[max_n+1],nxt[max_n+2][max_k+1],hsh[max_n+1][max_k+1];
char s[max_n+1],t[max_n+1];
int main(){
	uint n,m,*ans=pos,hash1,hash2=0,mxpos;
	scanf("%u%u%s%s",&n,&m,s+1,t+1);
	pwb[0]=1,mxpos=n-m+1;
	for(uint i=0; ++i<=n; pwb[i]=pwb[i-1]*bas,s[i]-='a'-1);
	for(uint i=0; ++i<=m; hash2=hash2*bas+(t[i]-='a'-1));
	for(uint i=0; ++i<=k; nxt[n+1][i]=n+1);
	for(uint i=n+1; --i; )
		for(int j=0; ++j<=k; nxt[i][j]=(s[i]==j)?i:nxt[i+1][j]);
	for(uint i=0; ++i<=n; )
		for(int j=0; ++j<=k; hsh[i][j]=hsh[i-1][j]*bas+(s[i]==j));
	for(uint i=0; ++i<=mxpos; hash1==hash2&&(*++ans=i)){
		hash1=0,memset(b,0,sizeof(b));
		for(uint j=0,p; ++j<=k; )
			if(nxt[i][j]<=i+m-1){
				!(b[p=t[nxt[i][j]-i+1]]||b[j])&&(b[p]=j,b[j]=p);
				hash1+=b[j]*(hsh[i+m-1][j]-hsh[i-1][j]*pwb[m]);
			}
	}
	printf("%d\n",ans-pos);
	for(uint*i=pos; ++i<=ans; printf("%u ",*i));
	return 0;
}