//CF1009G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
char ch[N];
int n,a[N],b[N],f[66],g[66];
int chk(int x,int y){
	int i,o=1;
	for(i=0;i<64;i=i+1){
		if(i&(1<<x))
			f[i]--;
		if((i|y)==i)
			g[i]--;
		if(f[i]<g[i])
			o=0;
	}
	if(o)
		return 1;
	for(i=0;i<64;i=i+1){
		if(i&(1<<x))
			f[i]++;
		if((i|y)==i)
			g[i]++;
	}
	return 0;
}
int main()
{
	int m,i,x;
	scanf("%s%d",ch+1,&m);
	n=strlen(ch+1);
	for(i=1;i<=n;i=i+1)
		a[i]=63,f[1<<(ch[i]-'a')]++;
	while(m--){
		scanf("%d%s",&x,ch+1);
		a[x]=0;
		for(i=1;ch[i];i=i+1)
			a[x]|=(1<<(ch[i]-'a'));
	}
	for(i=1;i<=n;i=i+1)
		g[a[i]]++;
	for(x=0;x<6;x=x+1)
		for(i=0;i<64;i=i+1)
			if(i&(1<<x))
				f[i]+=f[i^(1<<x)],g[i]+=g[i^(1<<x)];
	for(i=0;i<64;i=i+1){
		if(f[i]<g[i]){
			cout<<"Impossible";
			return 0;
		}
	}
	for(i=1;i<=n;i=i+1){
		for(x=0;x<6;x=x+1){
			if((a[i]&(1<<x))&&chk(x,a[i])){
				b[i]=x;
				break;
			}
		}
	}
	for(i=1;i<=n;i=i+1)
		cout<<(char)(b[i]+'a');
	return 0;
}