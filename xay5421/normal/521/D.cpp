#include<bits/stdc++.h>
#define fi first
#define se second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
typedef pair<pair<int,LL>,int> tp;
const int N=100005;
int n,m,K,num[N],t[N],A[N],B[N];
pair<int,int>ass[N];
vector<pair<int,int> >add[N];
vector<tp>mul;
int main(){
	scanf("%d%d%d",&K,&n,&m);
	rep(i,1,K)scanf("%d",num+i);
	rep(i,1,n)scanf("%d%d%d",t+i,A+i,B+i);
	rep(i,1,n){
		if(t[i]==1)ass[A[i]]=max(ass[A[i]],{B[i],i});else
		if(t[i]==2)add[A[i]].PB({B[i],i});else
			mul.PB({{B[i]-1,1},i});
	}
	rep(i,1,K){
		if(ass[i].fi>num[i])add[i].PB({ass[i].fi-num[i],ass[i].se});
	}
	rep(i,1,K){
		sort(add[i].begin(),add[i].end(),[&](pair<int,int>k1,pair<int,int>k2){return k1>k2;});
		LL sum=num[i];
		rep(j,0,SZ(add[i])-1){
			mul.PB({{add[i][j].fi,sum},add[i][j].se});
			sum+=add[i][j].fi;
		}
	}
	sort(mul.begin(),mul.end(),[&](tp k1,tp k2){
		return 1LL*k1.fi.fi*k2.fi.se>1LL*k2.fi.fi*k1.fi.se;
	});
	m=min(m,SZ(mul));
	sort(mul.begin(),mul.begin()+m,[&](tp k1,tp k2){
		return t[k1.se]<t[k2.se];
	});
	printf("%d\n",m);
	rep(i,0,m-1)printf("%d ",mul[i].se);
	return 0;
}