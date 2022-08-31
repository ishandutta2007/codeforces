//CF908G
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
const int N = 777;
const int MO = 1e9+7;
string s;
int n,a[11];
LL ans,p[N],f[N][N][11];
int main()
{
	int i,j,k,l,o;
	cin>>s;
	n=s.length();
	p[0]=0;
	for(i=1;i<=n;i=i+1)
		p[i]=(p[i-1]*10+1)%MO;
	for(k=0;k<=9;k=k+1)
		f[0][0][k]=1;
	for(i=1;i<=n;i=i+1){
		for(j=0;j<=i;j=j+1){
			for(k=0;k<=9;k=k+1){
				f[i][j][k]+=f[i-1][j][k]*k;
				if(j)
					f[i][j][k]+=f[i-1][j-1][k]*(10-k);
				f[i][j][k]%=MO;
			}
		}
	}
	for(i=0;i<n;i=i+1){
		o=s[i]-'0';
		if(i!=n-1)
			o--;
		for(l=0;l<=o;l=l+1){
			a[l]++;
			for(j=0;j<n-i;j=j+1)
				for(k=1;k<=9;k=k+1)
					ans+=f[n-i-1][j][k]*p[j+a[k]]%MO;
		}
		a[o+1]++;
	}
	cout<<ans%MO;
	return 0;
}