//CF 848C
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
typedef long long LL;
const int N = 111111;
const int Q = 1111;
const int M = 111;
int n,a[N],b[N],q;
int m,w[N],T[N][M];
set<int> S[N];
set<int>::iterator it;
void mo(int i,int j,int x){
	while(i<=n){
		T[i][j]+=x;
		i+=i&-i;
	}
}
void modify(int i,int f){
	if(b[i])
		mo(b[i],w[i],f*(i-b[i]));
}
int qu(int i,int j){
	int x=0;
	while(i){
		x+=T[i][j];
		i-=i&-i;
	}
	return x;
}
int query(int i,int j){
	return qu(n,j)-qu(i-1,j);
}
int main()
{
	int i,h,x,y;
	LL ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1){
		if(i%Q==1)
			m++;
		w[i]=m;
		scanf("%d",a+i);
		if(!S[a[i]].empty()){
			b[i]=*S[a[i]].rbegin();
			modify(i,1);
		}
		S[a[i]].insert(i);
		//cout<<b[i]<<endl;
	}
	while(q--){
		scanf("%d%d%d",&h,&x,&y);
		if(h==1){
			if(a[x]==y)
				continue;
			S[a[x]].erase(x);
			it=S[a[x]].lower_bound(x);
			if(it!=S[a[x]].end()){
				modify(*it,-1);
				b[*it]=b[x];
				modify(*it,1);
			}
			modify(x,-1);
			b[x]=0;
			a[x]=y;
			it=S[a[x]].lower_bound(x);
			if(it!=S[a[x]].end()){
				modify(*it,-1);
				b[x]=b[*it];
				b[*it]=x;
				modify(*it,1);
			}
			else{
				if(it!=S[a[x]].begin()){
					it--;
					b[x]=*it;
				}
			}
			modify(x,1);
			S[a[x]].insert(x);
		}
		else{
			ans=0;
			if(w[x]==w[y]){
				for(i=x;i<=y;i=i+1)
					if(b[i]>=x)
						ans+=i-b[i];
			}
			else{
				for(i=x;w[i]==w[x];i=i+1)
					if(b[i]>=x)
						ans+=i-b[i];
				for(i=y;w[i]==w[y];i=i-1)
					if(b[i]>=x)
						ans+=i-b[i];
				for(i=w[x]+1;i<w[y];i=i+1)
					ans+=query(x,i);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}