#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-15;
mt19937 rd(time(0));
int n,m,o,flag;
db a[200];
vector<pair<db,db> > b;
void out(db x,db y){
	if(flag)swap(x,y);
	b.push_back(make_pair(x,y));
}
void print(){
	printf("? %u\n",b.size());
	for(auto p:b)printf("%.15lf %.15lf\n",p.first,p.second);
	fflush(stdout);	
}
db ask(){
	b.clear();
	out(0,0),out(n,0);
	for(int i=1;i<=o;i++){
		if(i&1)out(n,a[i]),out(eps,a[i]);
		else out(eps,a[i]),out(n,a[i]);	
	}
	if(o%2==0)out(n,m),out(0,m);
	print();
	db res;cin>>res;
	return res;
}
db solve(){
	a[1]=((long long)rd()+1000)*1e-10;
	for(o=1;a[o]+1<m;o++)a[o+1]=a[o]+1;
	db res1=ask();
	for(int i=1;i<=o;i++)a[i]-=i*1e-10;
	db res2=ask();
	int x=abs(res1-res2)*1e10+0.5;
	if(x&1)return a[x]-res1;
	else return a[x]-(1-res1);
}
int main(){
	cin>>n>>m;
	db Y=solve();
	flag=1,swap(n,m);
	db X=solve();
	printf("! %.15lf %.15lf",X,Y);
	fflush(stdout);
	return 0;
}