//CF 889B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
char ch[111111];
int a[33],f[33],nx[33],pr[33],ans[33];
void bad(){
	cout<<"NO\n";
	exit(0);
}
int main()
{
	int n,i,j,l,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",&ch);
		l=strlen(ch);
		for(j=0;j<=26;j=j+1)
			a[j]=0;
		for(j=0;j<l;j=j+1){
			x=ch[j]-96;
			f[x]=1;
			if(a[x])
				bad();
			a[x]=1;
			if(j){
				y=ch[j-1]-96;
				if(nx[y]&&nx[y]!=x)
					bad();
				if(pr[x]&&pr[x]!=y)
					bad();
				nx[y]=x;
				pr[x]=y;
			}
		}
	}
	x=0;
	for(i=1;i<=26;i=i+1){
		for(j=1;j<=26;j=j+1)
			if(f[j]&&!pr[j])
				break;
		if(j>26)
			break;
		while(j){
			ans[++x]=j+96;
			f[j]=0;
			j=nx[j];
		}
	}
	for(i=1;i<=26;i=i+1)
		if(f[i])
			bad();
	for(i=1;i<=x;i=i+1)
		cout<<(char)ans[i];
	cout<<endl;
	return 0;
}