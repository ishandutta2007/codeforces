//CF1746E2
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
const int N = 222;
int n,m=10,f[N][N],g[N][N],h[N][N];
vector<int> a,b,c,d;
char ch[5];
int q(vector<int>&v){
	int i;
	printf("? %d ",v.size());
	for(i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",ch);
	return ch[0]=='Y';
}
void chk(int x){
	printf("! %d\n",x);
	fflush(stdout);
	scanf("%s",ch);
	if(ch[1]==')')
		exit(0);
}
int main()
{
	int i,j,r,l,x,y;
	n=m;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			f[i][j]=N;
	for(l=0;l<=n;l++){
		for(i=0,j=l;i<=l;i++,j--){
			if(l<=2){
				f[i][j]=0;
				continue;
			}
			for(x=0;x<=i;x++)
				for(y=0;y<=j;y++)
					if(f[i][j]>max(f[x+y][i-x],f[i-x+j-y][x])+1){
						f[i][j]=max(f[x+y][i-x],f[i-x+j-y][x])+1;
						g[i][j]=x;
						h[i][j]=y;
					}
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a.push_back(i);
	while(a.size()+b.size()>=3){
		c.clear();
		d.clear();
		if(a.size()+b.size()<=m){
			x=g[a.size()][b.size()];
			y=h[a.size()][b.size()];
		}
		else{
			x=a.size()/2;
			y=(b.size()+1)/2;
		}
		for(i=0;i<a.size();i++){
			if(i<x)
				c.push_back(a[i]);
			else
				d.push_back(a[i]);
		}
		for(i=0;i<b.size();i++){
			if(i<y)
				c.push_back(b[i]);
			else
				d.push_back(b[i]);
		}
		r=q(c);
		if(!r)
			swap(c,d);
		b.clear();
		sort(c.begin(),c.end());
		for(i=0,j=0;i<a.size();i++){
			while(j<c.size()&&c[j]<a[i]){
				j++;
			}
			if(j<c.size()&&c[j]==a[i])
				continue;
			b.push_back(a[i]);
		}
		swap(c,a);
	}
	for(i=0;i<a.size();i++)
		chk(a[i]);
	for(i=0;i<b.size();i++)
		chk(b[i]);
	return 0;
}