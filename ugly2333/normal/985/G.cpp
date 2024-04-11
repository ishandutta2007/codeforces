//CF 985G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef unsigned long long LL;
const int N = 222222;
int n,m;
LL a,b,c;
vector<int> v[N];
LL ans,t,s[N],e[N],p[N];
LL getm(int l,int r){
	return (LL)(l+r)*(r-l+1)/2;
}
int chk(int x,int y){
	LL r=(LL)x*N+y,w=(LL)y*N+x;
	if(*lower_bound(e,e+m,r)==r)
		return 1;
	if(*lower_bound(e,e+m,w)==w)
		return 1;
	return 0;
}
int main()
{
	int i,j,x,y,z,w;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
	a=x,b=y,c=z;
	for(i=0;i<m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		e[i]=(LL)x*N+y;
	}
	sort(e,e+m);
	n--;
	for(i=0;i<=n;i=i+1){
		ans+=a*i*getm(0,n-i-1)+b*i*i*(n-i)+c*i*getm(0,i-1);
		
		sort(v[i].begin(),v[i].end());
		y=v[i].size();
		t=0,z=0;
		for(x=0;x<=y;x=x+1)
			s[x]=0;
		for(x=0;x<y;x=x+1){
			j=v[i][x];
			if(j<i)
				t+=j,z++;
			if(x)
				s[x]+=s[x-1];
			s[x+1]+=j;
		}
		for(x=y;x--;){
			j=v[i][x];
			if(j<i){
				ans-=a*getm(0,j-1)+b*j*j+c*i*j;
				ans-=a*j*(i-j-1)+b*getm(j+1,i-1)+c*i*(i-j-1);
				ans-=a*j*(n-i)+b*i*(n-i)+c*getm(i+1,n);
				
				ans+=a*s[x]+b*j*x+c*i*x;
			}
			else{
				ans+=a*t+b*i*z+c*j*z;
				ans+=a*i*(x-z)+b*(s[x]-t)+c*j*(x-z);
			}
		}
		
		if(y*y<n){
			for(x=y;x--;)
				for(j=x;j--;){
					z=v[i][j],w=v[i][x];
					if(i<z&&chk(z,w))
						ans-=a*i+b*z+c*w;
				}
		}
		else{
			for(x=y;x--;)
				p[v[i][x]]=1;
			for(j=0;j<=n;j=j+1){
				if(!p[j])
					continue;
				for(x=v[j].size();x--;){
					z=v[j][x];
					if(i<j&&j<z&&p[z])
						ans-=a*i+b*j+c*z;
				}
				p[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}