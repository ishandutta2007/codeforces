//CF1477E
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
const int W = 1111111;
int n,m,q,a[N],b[N];
LL sa,sb;
int w=1e6+1,t[W];
LL g[W];
multiset<int> A,B;
multiset<int>::iterator it;
void ad(int x,int y){
	int z=x*y;
	x++;
	while(x<=w){
		t[x]+=y;
		g[x]+=z;
		x+=x&-x;
	}
}
void qu(int x,int&y,LL&z){
	x++;
	while(x){
		y+=t[x];
		z+=g[x];
		x-=x&-x;
	}
}
LL ansb(int p){
	int o=min(*A.begin(),*B.begin());
	if(p<=o)
		return sa-(LL)p*n-sb+(LL)p*m;
	int x=0;
	LL y=0;
	qu(p,x,y);
	return sa-(LL)o*n-sb+(LL)p*(m-x)+y;
}
LL ansa(int p){
	int o=min(*A.begin(),*B.begin());
	if(p<=o)
		return ansb(p);
	return ansb(p)-(p-o);
}
int main()
{
	int i,x,y,o;
	LL s;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		sa+=a[i];
		A.insert(a[i]);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d",b+i);
		sb+=b[i];
		ad(b[i],1);
		B.insert(b[i]);
	}
	while(q--){
		scanf("%d%d",&i,&x);
		if(i<=2){
			scanf("%d",&y);
			if(i==1){
				A.erase(A.find(a[x]));
				sa-=a[x];
				A.insert(y);
				sa+=y;
				a[x]=y;
			}
			else{
				B.erase(B.find(b[x]));
				sb-=b[x];
				ad(b[x],-1);
				B.insert(y);
				sb+=y;
				ad(y,1);
				b[x]=y;
			}
		}
		else{
			s=max(ansb(*B.begin()-x),ansb(*B.rbegin()-x));
			s=max(s,max(ansa(*A.begin()-x),ansa(*A.rbegin()-x)));
			o=min(*A.begin(),*B.begin());
			it=A.lower_bound(o+x);
			if(it!=A.end())
				s=max(s,ansa(*it-x));
			if(it!=A.begin()){
				it--;
				s=max(s,ansa(*it-x));
			}
			it=A.lower_bound(*B.rbegin()+x);
			if(it!=A.end())
				s=max(s,ansa(*it-x));
			if(it!=A.begin()){
				it--;
				s=max(s,ansa(*it-x));
			}
			printf("%lld\n",s);
		}
	}
	return 0;
}