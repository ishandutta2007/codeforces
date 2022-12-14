#include <cstdio>
#include <cstring>
#define max_ai 999
#define max_n 1009
using namespace std;
int ton[max_ai+1],fst[max_ai+1],scd[max_ai+1];
int a[max_n+1],b[max_n+1];
int main(){
	int n,m,cnt;
	scanf("%d",&n);
	m=n<<1,memset(ton,0,sizeof(ton)),memset(b,0,sizeof(b)),cnt=0;
	for(int i=0; ++i<=m; ){
		scanf("%d",a+i);
		switch(++ton[a[i]]){
			case 1:
				fst[a[i]]=i;
				break;
			case 2:
				scd[a[i]]=i;
				break;
		}
	}
	for(int i=9; ++i<=99; ton[i]>1&&(b[fst[i]]=1,b[scd[i]]=2,++cnt));
	int idx=0;
	for(int i=9; ++i<=99; ton[i]==1&&((idx^=1)?(b[fst[i]]=1,++cnt):(b[fst[i]]=2)));
	int i=0;
	for(; cnt<n; b[++i]||(b[i]=1,++cnt));
	for(; ++i<=m; b[i]||(b[i]=2));
	int cnta=0,cntb=0;
	memset(ton,0,sizeof(ton));
	for(int i=0; ++i<=m; b[i]==1&&(++ton[a[i]]));
	for(int i=9; ++i<=99; cnta+=bool(ton[i]));
	memset(ton,0,sizeof(ton));
	for(int i=0; ++i<=m; b[i]==2&&(++ton[a[i]]));
	for(int i=9; ++i<=99; cntb+=bool(ton[i]));
//	printf("%d %d\n",cnta,cntb);
	printf("%d\n",cnta*cntb);
	for(int i=0; ++i<=m; printf("%d ",b[i]));
	return 0;
}