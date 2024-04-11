#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,m,t[1010],l[1010],r[1010],srt[1010],ans[1010];
int dsu[1010];
int fnd(int x){ return (x == dsu[x])?x:dsu[x] = fnd(dsu[x]); }
void merge(int u,int v){ dsu[fnd(u)] = fnd(v);}
int main() {
	read(n);read(m);
	for(int i=1;i<=n;i++)dsu[i] = i;
	for(int i=0;i<m;i++){
		read(t[i]);read(l[i]);read(r[i]);
		if(t[i])for(int j=l[i];j<=r[i];j++){
			if(fnd(j)!=fnd(l[i]))merge(j,l[i]);
		}
	}
	int p = 1,mx = 10000000;
	while(p<=n){
		int lp = p;
		while(fnd(p) == fnd(lp)){
			ans[p] = mx;
			mx+=1;
			p+=1;
		}
		
		mx-=1000;
	}
	//for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	for(int i=0;i<m;i++){
		if(t[i] == 0){
			int asc = 1;
			for(int j=l[i];j<r[i];j++){
				if(ans[j]>ans[j+1])asc = 0;
			}
			if(asc){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	return 0;
}