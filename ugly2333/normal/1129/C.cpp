//CF1129C
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
const int N = 3033;
const int B = 233;
const int MO = 1e9+7;
const int MO2 = 1e9+9;
int n,a[N],b[N];
int bb(int i){
	int x=a[i-3]*8+a[i-2]*4+a[i-1]*2+a[i];
	if(x==3||x==5||x==14||x==15)
		return 0;
	return 1;
}
LL f[N][N],h[N][N],h2[N][N],s[N];
set<LL> S;
int main()
{
	int i,j,o;
	LL t;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=4;i<=n;i=i+1)
		b[i]=bb(i);
	for(i=1;i<=n;i=i+1){
		f[i][i-1]=1;
		for(j=i;j<=n;j=j+1){
			f[i][j]=0;
			if(j>0)
				f[i][j]+=f[i][j-1];
			if(j>1)
				f[i][j]+=f[i][j-2];
			if(j>2)
				f[i][j]+=f[i][j-3];
			if(b[j])
				f[i][j]+=f[i][j-4];
			f[i][j]%=MO;
			h[i][j]=((LL)h[i][j-1]*B%MO+a[j]+1)%MO;
			h2[i][j]=((LL)h2[i][j-1]*B%MO2+a[j]+1)%MO2;
		}
	}
	for(o=1;o<=n;o=o+1){
		S.clear();
		for(j=o;j<=n;j=j+1){
			i=j-o+1;
			t=h[i][j]<<32|h2[i][j];
			if(S.find(t)!=S.end())
				continue;
			S.insert(t);
			s[j]+=f[i][j];
		}
	}
	for(i=1;i<=n;i=i+1){
		s[i]+=s[i-1];
		s[i]%=MO;
		cout<<s[i]<<endl;
	}
	return 0;
}