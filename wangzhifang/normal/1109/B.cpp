#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 5000
#define max_char 122
using namespace std;
char s[max_n<<1|1],s2[max_n<<2];
int nxt[max_n<<1|1],pl[max_n<<2],ton[max_char+1];
bool chk[max_n<<1|1];
bool chkimp(char*s,int&n){
	char*ed;
	for(ed=s; *(++ed); ++ton[*ed]);
	n=(--ed)-s;
	return ton[*ed]>=n-1||ton[*(ed-1)]==n-1;
}
void kmp(char*s,int n,int*nxt){
	for(int i=1,j=(nxt[1]=/*nxt[0]=*/0); ++i<=n; nxt[i]=j)
		for(; (s[i]!=s[j+1]||(++j,0))&&j; j=nxt[j]);
}
void manacher(char*s,int n,char*t,int*pl){
	int m=(n<<1)-1,maxright=0,mid;
	for(int i=0; ++i<n; t[i<<1]='#',t[(i<<1)-1]=s[i]);
	t[m]=s[n];
	for(int i=0; ++i<=m; pl[i]+i>maxright&&(maxright=pl[i]+i,mid=i))
        for(pl[i]=i<maxright?min(pl[(mid<<1)-i],pl[mid]+mid-i):1; i>pl[i]&&i+pl[i]<=m&&t[i+pl[i]]==t[i-pl[i]]; ++pl[i]);
}
bool chk1(int n,int m,int*nxt,int*pl){
	if(n&1)
		for(int i=0; ++i<m; pl[i<<1|1]>=n&&(chk[i+(n>>1)+1]=1));
	else
		for(int i=0; ++i<m; pl[i<<1]>=n&&(chk[i+(n>>1)]=1));
	for(int i=n; ++i<=m; ){
		nxt[i]>n&&(nxt[i]=nxt[nxt[i]]);
		if(nxt[i]<n&&chk[i])
			return 1;
	}
	return 0;
}
int main(){
	int n,m;
	scanf("%s",s+1);
	if(chkimp(s,n)){
		puts("Impossible");
		return 0;
	}
	memcpy(s+n+1,s+1,n*sizeof(char)),m=n<<1;
	kmp(s,m,nxt);
	manacher(s,m,s2,pl);
	if(chk1(n,m,nxt,pl))
		puts("1");
	else
		puts("2");
	return 0;
}