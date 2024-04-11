//CF1450C1
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
const int N = 333;
int n,a[N][N],d[N][N],b[5],e[5];
char c[N];
string s=".XO";
int main()
{
	int T,i,j,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i=i+1){
			scanf("%s",c+1);
			for(j=1;j<=n;j=j+1){
				a[i][j]=c[j]=='X';
				d[i][j]=c[j]=='O';
			}
		}
		for(i=0;i<3;i=i+1)
			b[i]=0,e[i]=0;
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				b[(i+j)%3]+=a[i][j],e[(i+j)%3]+=d[i][j];
		o=0;
		for(i=0;i<3;i=i+1)
			if(b[i]+e[(i+1)%3]<b[o]+e[(o+1)%3])
				o=i;
		for(i=1;i<=n;i=i+1){
			for(j=1;j<=n;j=j+1){
				if(a[i][j]&&(i+j)%3==o)
					a[i][j]=2;
				if(d[i][j]&&(i+j)%3==(o+1)%3)
					d[i][j]=2;
			}
		}
		for(i=1;i<=n;i=i+1){
			for(j=1;j<=n;j=j+1){
				cout<<s[(a[i][j]-d[i][j]+3)%3];
			}
			cout<<endl;
		}
	}
	return 0;
}