#include <cmath>
#include <cstdio>

#define MAXB 505
#define MAXN 100005

int n,s[MAXB],sz[MAXB],bel[MAXN],B;

int main(){
	scanf("%d",&n); B=sqrt(n);
	for (int i=1;i<=n;i++) bel[i]=(i-1)/B+1,sz[bel[i]]++;
	s[bel[n]]=1;
	for (int i=bel[n]-1;i;i--){
		s[i]=s[i+1]+sz[i+1];
	}
	for (int i=1;i<=n;i++) printf("%d ",s[bel[i]]++);
	return 0;
}