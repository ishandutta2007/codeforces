#include<bits/stdc++.h>
using namespace std;
int n,k;
struct sb{
	int a,b;
}s[1100];
bool cmp(sb p,sb o){
	return p.a<o.a;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int pp=0;pp<T;pp++){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&s[i].a);
		for(int i=1;i<=n;i++) scanf("%d",&s[i].b);
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(k<s[i].a) break;
			k+=s[i].b;
		}
		printf("%d\n",k);
	}
	return 0;
}