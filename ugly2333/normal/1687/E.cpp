//CF1687E
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
const int N = 1111111;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n,a[N],f[N],g[N];
vector<int> v,p,c;
vector<vector<int> > s;
void go(int d){//cout<<d<<endl;
	int i,j,m,w;
	vector<int> t;
	sort(c.begin(),c.end());
	c.resize(unique(c.begin(),c.end())-c.begin());
	reverse(c.begin(),c.end());
	m=c.size(),w=1<<m;
	for(i=1;i<w;i++){
		t.clear();
		for(j=0;j<m;j++)
			if(i&(1<<j))
				t.push_back(c[j]);
		t.push_back(t.size());
		t.push_back((t.size()&1)^d);
		reverse(t.begin(),t.end());
		s.push_back(t);
	}
}
int main()
{
	int i,j,k,l,x,y,z,w,o;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		f[i]=gcd(f[i-1],a[i]);
	for(i=n;i>=1;i--)
		g[i]=gcd(g[i+1],a[i]);
	for(i=1;i<=n;i++)
		if(gcd(f[i-1],g[i+1])!=f[n])
			v.push_back(i);
	v.push_back(1);
	for(j=0;j<v.size();j++){
		x=a[v[j]];
		p.clear();
		for(i=2;i*i<=x;i++){
			if(x%i==0){
				p.push_back(i);
				while(x%i==0){
					x/=i;
				}
			}
		}
		if(x>1)
			p.push_back(x);
		c.clear();
		o=0;
		for(k=0;k<p.size();k++){
			y=p[k];
			l=0;
			w=N;
			for(i=1;i<=n;i++){
				if(i==v[j])
					continue;
				x=a[i];
				z=0;
				while(x%y==0){
					x/=y;
					z++;
				}
				if(w>z)
					l=i,w=z;
			}
			c.push_back(l);
			o=gcd(o,a[l]);
		}
		if(o==0){
			for(i=1;i<=n;i++)
				if(i!=v[j]){
					o=a[i];
					c.push_back(i);
					break;
				}
		}
		x=o;
		p.clear();
		for(i=2;i*i<=x;i++){
			if(x%i==0){
				p.push_back(i);
				while(x%i==0){
					x/=i;
				}
			}
		}
		if(x>1)
			p.push_back(x);
		for(k=0;k<p.size();k++){
			y=p[k];
			l=0;
			w=N;
			for(i=1;i<=n;i++){
				if(i==v[j])
					continue;
				x=a[i];
				z=0;
				while(x%y==0){
					x/=y;
					z++;
				}
				if(w>z)
					l=i,w=z;
			}
			c.push_back(l);
		}
		if(j!=v.size()-1){
			go(0);
			c.push_back(v[j]);
			go(1);
		}
		else{
			c.push_back(v[j]);
			go(0);
			go(0);
		}
	}
	printf("%d\n",s.size());
	for(i=0;i<s.size();i++){
		for(j=0;j<s[i].size();j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
	return 0;
}