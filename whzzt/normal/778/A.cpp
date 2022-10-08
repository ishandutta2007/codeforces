#include"bits/stdc++.h"
#define ifor(i,l,r) for(register int i=l;i<=r;i++)

using namespace std;

const int N = 200005;
char a[N],b[N];
int c[N],n;
bool v[N];

bool check(int mid){
	memset(v,false,sizeof(v));
	for(int i=1;i<=mid;i++)v[c[i]]=true;
	int l=strlen(b+1),pos=1;
	for(int i=1;i<=n&&pos<=l;i++)if(!v[i]&&b[pos]==a[i])pos++;
	return pos>l;
}

int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	int bt=1,tp=n,md=(n+1)>>1;
	while(bt<tp){
		if(check(md)) bt=md;
		else tp=md-1;
		md=(bt+tp+1)>>1;
	}
	if(!check(md))puts("0");
	else printf("%d",md);
	return 0;
}