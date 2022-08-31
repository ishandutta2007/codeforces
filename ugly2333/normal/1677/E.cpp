//
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
const int Q = 1111111;
int n,q,a[N],p[N],l[N],r[N];
LL t[N][4],ans[Q];
int ql[Q],qr[Q];
set<int> S;
set<int>::iterator it;
vector<pair<pair<int,int>,pair<int,int> > > v[N];
vector<pair<int,int> > vi[N];
vector<int> vq[N];
void ad(int x,int j,LL y){
	x=n-x;
	while(x<=n){
		t[x][j]+=y;
		x+=x&-x;
	}
}
LL qu(int x,int j){
	x=n-x;
	LL y=0;
	while(x){
		y+=t[x][j];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,j,k,cl,cr,o;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),p[a[i]]=i;
	S.insert(0);
	S.insert(n+1);
	for(i=n;i>=1;i--){
		it=S.lower_bound(p[i]);
		r[i]=(*it)-1;
		it--;
		l[i]=(*it)+1;
		S.insert(p[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n/i;j++){
			k=i*j;
			cl=min(min(p[i],p[j]),p[k]);
			cr=max(max(p[i],p[j]),p[k]);
			if(l[k]<=cl&&cr<=r[k]){
				vi[k].push_back(make_pair(cr,cl));
				//cout<<i<<j<<' '<<l[k]<<cl<<' '<<cr<<r[k]<<endl;
			}
		}
	}
	for(k=1;k<=n;k++){
		if(!vi[k].size())
			continue;
		sort(vi[k].begin(),vi[k].end());
		o=l[k]-1;
		for(i=0;i<vi[k].size();i++){
			cl=vi[k][i].second;
			cr=vi[k][i].first;
			if(cl>o){
				v[cr].push_back(make_pair(make_pair(o,1),make_pair(o+1,cr-1)));
				v[cr].push_back(make_pair(make_pair(cl,-1),make_pair(cl+1,cr-1)));
				v[r[k]+1].push_back(make_pair(make_pair(o,-1),make_pair(o+1,r[k])));
				v[r[k]+1].push_back(make_pair(make_pair(cl,1),make_pair(cl+1,r[k])));
				o=cl;
			}
		}
	}
				
	for(i=1;i<=q;i++){
		scanf("%d%d",ql+i,qr+i);
		vq[qr[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j++){
			o=v[i][j].first.first;
			k=v[i][j].first.second;
			cl=v[i][j].second.first;
			cr=v[i][j].second.second;//cout<<o<<' '<<k<<' '<<cl<<' '<<cr<<endl;
			ad(o,0,k);
			ad(o,1,(LL)k*cl);
			ad(o,2,(LL)k*cr);
			ad(o,3,(LL)k*cl*cr);
		}
		for(j=0;j<vq[i].size();j++){
			o=vq[i][j];//cout<<o<<' '<<qu(ql[o],0)<<' '<<qu(ql[o],1)<<' '<<qu(ql[o],2)<<' '<<qu(ql[o],3)<<endl;
			ans[o]+=(LL)ql[o]*qr[o]*qu(ql[o],0);
			ans[o]-=(LL)qr[o]*qu(ql[o],1);
			ans[o]-=(LL)ql[o]*qu(ql[o],2);
			ans[o]+=(LL)qu(ql[o],3);
		}
	}
	for(i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}