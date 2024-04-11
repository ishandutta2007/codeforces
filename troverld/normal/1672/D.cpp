#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100],b[200100];
vector<int>v[200100];
bool era[200100];
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)v[i].clear(),era[i]=false;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=n,j=n;i;i--){
		bool fd=(a[j]==b[i]);
//		printf("%d,%d:%d\n",i,j,fd);
		while(era[j]&&!fd)fd|=(a[--j]==b[i]);
//		printf("%d,%d:%d\n",i,j,fd);
		if(!fd){puts("No");return;}
		era[v[b[i]].back()]=true,v[b[i]].pop_back();
	}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}