//CF1427C
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
const int R = 555;
const int N = 111111;
void cmax(int&x,int y){
	if(x<y)
		x=y;
}
int r,n,a[N],b[N],t[N],f[N];
int ab(int x){
	if(x<0)
		return -x;
	return x;
}
int main()
{
	int i,j,w,o,p,x,y;
	scanf("%d%d",&r,&n);
	a[0]=1,b[0]=1,t[0]=0,f[0]=N;
	w=0,o=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&p,&x,&y);
		while(o<i&&t[o]<=p-r*2){
			cmax(w,f[o]);
			o++;
		}
		f[i]=w;
		for(j=o;j<i;j=j+1)
			if(ab(x-a[j])+ab(y-b[j])<=p-t[j])
				cmax(f[i],f[j]);
		f[i]++;
		a[i]=x,b[i]=y,t[i]=p;
	}
	w=0;
	for(i=0;i<=n;i=i+1)
		cmax(w,f[i]);
	cout<<w-N;
	return 0;
}