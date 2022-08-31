//CF1621C
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
const int N = 11111;
int n,m,p[N];
int qu(int i){
	cout<<"? "<<i<<endl;
	cin>>i;
	return i;
}
int main()
{
	int T,i,x,y;
	cin>>T;
	while(T--){
		cin>>n;
		memset(p,0,sizeof(p));
		for(i=1;i<=n;i++){
			if(p[i])
				continue;
			x=qu(i);
			while(1){
				y=qu(i);
				p[x]=y;
				x=y;
				if(p[y])
					break;
			}
		}
		cout<<"!";
		for(i=1;i<=n;i++)
			cout<<' '<<p[i];
		cout<<endl;
	}
	return 0;
}