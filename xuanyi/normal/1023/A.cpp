#include <cstdio>
#include <cstring>

int n,m,l,r,r2,pos=-1;
char s[200005],t[200005];

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	l=0,r=n-1,r2=m-1;
	while (l<n && s[l]==t[l]) l++;
	if (l==n && l==m){
		puts("YES");
		return 0;
	} else if (s[l]!='*' && s[l]!=t[l]){
		puts("NO");
		return 0;
	}
	while (r>=0 && r2>=0 && s[r]==t[r2]) r--,r2--;
	if (s[r]=='*' && r2+1>=l){
		puts("YES");
	} 
	else puts("NO");
	return 0;
}