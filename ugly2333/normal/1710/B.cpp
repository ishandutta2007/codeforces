//CF1710B
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
const int N = 222222;
int n,m,a[N],b[N];
map<int,LL> m1,m0;
map<int,LL>::iterator it1,it0;
int main()
{
	int T,i,o;
	LL x,y,z,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		m1.clear();
		m0.clear();
		for(i=1;i<=n;i++){
			scanf("%d%d",a+i,b+i);
			m1[a[i]-b[i]]++;
			m0[a[i]-b[i]]+=b[i]-a[i];
			m1[a[i]]-=2;
			m0[a[i]]+=-(b[i]-a[i])+(a[i]+b[i]);
			m1[a[i]+b[i]]++;
			m0[a[i]+b[i]]-=a[i]+b[i];
		}
		x=0;
		y=0;
		o=0;
		for(it1=m1.begin(),it0=m0.begin();it1!=m1.end();it1++,it0++){
			x+=(*it1).second;
			y+=(*it0).second;
			z=x*(*it1).first+y;//cout<<(*it1).first<<' '<<z<<endl;
			if(z>m){
				if(o){
					s=max(s,(*it1).first+z);
					t=min(t,(*it1).first-z);
				}
				else{
					o=1;
					s=(*it1).first+z;
					t=(*it1).first-z;
				}
			}
		}
		s-=m;
		t+=m;
		for(i=1;i<=n;i++){
			if(!o||(a[i]+b[i]>=s&&a[i]-b[i]<=t))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}