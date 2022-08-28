//CF 1017D
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
const int N = 13;
const int W = 4111;
char ch[111];
int n,m,q,w,f[N];
int a[W],b[W],c[W][W];
pair<int,int> p[W];
int main()
{
	int i,j,x;
	scanf("%d%d%d",&n,&m,&q);
	w=1<<n;
	for(i=n-1;i>=0;i=i-1)
		scanf("%d",f+i);
	while(m--){
		scanf("%s",ch);
		i=0;
		for(j=0;j<n;j=j+1){
			i<<=1;
			if(ch[j]=='1')
				i++;
		}
		a[i]++;
	}
	for(i=0;i<w;i=i+1)
		for(j=0;j<n;j=j+1)
			if(i&(1<<j))
				b[i^(w-1)]+=f[j];
	for(i=0;i<w;i=i+1){
		for(j=0;j<w;j=j+1)
			c[i][b[i^j]]+=a[j];
		for(j=1;j<W;j=j+1)
			c[i][j]+=c[i][j-1];
	}
	sort(b,b+w);
	while(q--){
		scanf("%s%d",ch,&x);
		i=0;
		for(j=0;j<n;j=j+1){
			i<<=1;
			if(ch[j]=='1')
				i++;
		}
		cout<<c[i][x]<<endl;
	}
	return 0;
}