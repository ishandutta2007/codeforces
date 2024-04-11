#include <cstdio>
typedef long long ll;

#define MAXN 100005

int n; ll t[2][2];
char sa[MAXN],sb[MAXN];

int main(){
	scanf("%d",&n);
	scanf("%s%s",sa,sb);
	for (int i=0;i<n;i++) t[sa[i]-'0'][sb[i]-'0']++;
	printf("%lld\n",t[0][0]*(t[1][0]+t[1][1])+t[0][1]*t[1][0]);
	return 0;
}