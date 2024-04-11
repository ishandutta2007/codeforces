#include<bits/stdc++.h>
using namespace std;
int t,fa[100];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unnion(int x,int y){
	fa[y]=x;
}
int main(){
	scanf("%d\n",&t);
	while(t--){
		char s[100];
		cin.getline(s+1,19000);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)fa[i]=i; 
		for(int i=1;i<=n;i++)if(s[i]=='E')unnion(find(i),find((i)%n+1));
		int pd=0;
		for(int i=1;i<=n;i++)if(s[i]=='N')if(find(i)==find((i)%n+1))pd=1;
		puts(pd?"NO":"YES");
	}
	return 0;
}