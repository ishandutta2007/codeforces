#include<bits/stdc++.h>
using namespace std;
int n,q,nex[200100],las[200100],cnt,val[200100],id[200100],sum[200100][2];
char s[200100];
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int l=1,r;l<=n;l=r+1){
		for(r=l;r<n&&s[r+1]!=s[r];r++);
		++cnt;
		for(int i=l;i<=r;i++)nex[i]=r,las[i]=l,id[i]=cnt;
		val[cnt]=(s[r]-'0');
	}
	for(int i=1;i<=cnt;i++){
		sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
		sum[i][val[i]]++;
	}
//	for(int i=1;i<=cnt;i++)printf("%d ",val[i]);puts("");
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		if(id[l]==id[r]){puts("1");continue;}
		int res=id[r]-id[l]+1;
//		printf("[%d,%d]\n",id[l],id[r]);
		res-=min(sum[id[r]-1][0]-sum[id[l]-1][0],sum[id[r]-1][1]-sum[id[l]-1][1]);
		printf("%d\n",res);
	}
	return 0;
}
/*
6 1
111000
1 6
*/