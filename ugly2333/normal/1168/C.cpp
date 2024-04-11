//CF1168C
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
const int N = 333333;
int n,q,a[N],b[N],f[22][22],g[22],ql[N],qr[N],ans[N];
vector<int> v[N];
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		for(j=0;j<20;j=j+1)
			if(a[i]&(1<<j))
				b[i]=j;
	}
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",ql+i,qr+i);
		if(a[ql[i]]&&a[qr[i]])
			v[qr[i]].push_back(i);
	}
	for(i=1;i<=n;i=i+1){
		for(j=0;j<20;j=j+1)
			f[j][j]=i,g[j]=0;
		for(j=0;j<20;j=j+1)
			if(a[i]&(1<<j))
				for(k=0;k<20;k=k+1)
					g[k]=max(g[k],f[j][k]);
		for(j=0;j<20;j=j+1)
			if(a[i]&(1<<j))
				for(k=0;k<20;k=k+1)
					f[j][k]=g[k];
		for(j=0;j<v[i].size();j=j+1){
			k=v[i][j];
			if(f[b[qr[k]]][b[ql[k]]]>=ql[k])
				ans[k]=1;
		}
		/*for(j=0;j<3;j=j+1){
			for(k=0;k<3;k=k+1)
				cout<<f[j][k];
			cout<<endl;
		}cout<<endl;*/
	}
	for(i=1;i<=q;i=i+1){
		if(ans[i])
			cout<<"Shi\n";
		else
			cout<<"Fou\n";
	}
	return 0;
}