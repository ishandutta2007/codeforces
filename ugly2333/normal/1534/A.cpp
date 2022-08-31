//CF1534A
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
const int N = 111;
int n,m,a[N][N];
char ch[N];
int main()
{
	int T,i,j,f[2];
	cin>>T;
	while(T--){
		cin>>n>>m;
		f[0]=0,f[1]=0;
		for(i=1;i<=n;i++){
			cin>>ch;
			for(j=1;j<=m;j++){
				if(ch[j-1]=='W')
					f[(i+j)%2]|=1;
				if(ch[j-1]=='R')
					f[(i+j)%2]|=2;
			}
		}
		if(f[0]==3||f[1]==3||(f[0]&f[1])){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		if(f[0])
			f[1]=3^f[0];
		else{
			if(f[1])
				f[0]=3^f[1];
			else
				f[0]=1,f[1]=2;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(f[(i+j)%2]==1)
					cout<<'W';
				else
					cout<<'R';
			}
			cout<<endl;
		}
	}
	return 0;
}