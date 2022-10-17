#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int maxn=250005;
int n,m,mx,ps;
int tot[maxn],pos[maxn],ans[maxn],p[3];
vector<int>v[maxn];
int check(){
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=0;j<m;j++)
			t+=(ans[j]!=v[i][j]);
		if(t>2)
			return i;
	}
	puts("Yes");
	for(int i=0;i<m;i++)
		printf("%d%c",ans[i],i==m-1? '\n':' ');
	exit(0);
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=0,x;j<m;j++){
			scanf("%d",&x),v[i].push_back(x);
			if(i>1&&v[1][j]!=x)
				tot[i]++;
		}
		if(tot[i]>mx)
			mx=tot[i],ps=i;
	}
	if(mx>4){
		puts("No");
		return 0;
	}
	for(int i=0;i<m;i++)
		ans[i]=v[1][i];
	check();
	if(mx==3){
		int s=0;
		for(int i=0;i<m;i++)
			if(v[1][i]!=v[ps][i])
				pos[s++]=i;
		for(int i=0;i<3;i++)
			p[i]=i;
		for(int i=0;i<6;i++){
			ans[pos[p[0]]]=v[1][pos[p[0]]],ans[pos[p[1]]]=v[ps][pos[p[1]]],ans[pos[p[2]]]=v[1][pos[p[2]]];
			int q=check();
			ans[pos[p[2]]]=v[q][pos[p[2]]],check(),next_permutation(p,p+3);
		}
	}
	if(mx==4){
		int s=0;
		for(int i=0;i<m;i++)
			if(v[1][i]!=v[ps][i])
				pos[s++]=i;
		for(int i=0;i<16;i++)
			if(__builtin_popcount(i)==2){
				for(int j=0;j<4;j++)
					ans[pos[j]]=v[((i>>j)&1)? 1:ps][pos[j]];
				check();
			}
	}
	puts("No");
	return 0;
}