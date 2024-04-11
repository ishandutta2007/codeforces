#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
const int mo=998244353;
int n,m,Q,sum;
map<pair<int,int>, int> mp;

struct Tr{
	int a[N][2];
	long long sbad;
	long long suse;
	void insert(int x,int v){
		if (!a[x][0]&&!a[x][1]) ++suse;
		if (!a[x][v]&&a[x][v^1]) ++sbad;
		a[x][v]++;
	}
	void del(int x,int v){
		a[x][v]--;
		if (!a[x][0]&&!a[x][1]) --suse;
		if (!a[x][v]&&a[x][v^1]) --sbad;
	}
}T1,T2,T3;
void insert(int x,int y,int tp){
	++sum;
	T1.insert(y,(x^tp)&1);
	T2.insert(x,(y^tp)&1);
	T3.insert(0,(x^y^tp)&1);
}
void del(int x,int y,int tp){
	--sum;
	T1.del(y,(x^tp)&1);
	T2.del(x,(y^tp)&1);
	T3.del(0,(x^y^tp)&1);
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int count(){
	if (T1.sbad&&T2.sbad) return 0;
	if (T1.sbad) return power(2,n-T2.suse);
	if (T2.sbad) return power(2,m-T1.suse);
	return (power(2,n-T2.suse)+power(2,m-T1.suse)-(T3.sbad?0:power(2,1-T3.suse)))%mo;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=Q;i++){
		int x,y,tp;
		scanf("%d%d%d",&x,&y,&tp);
		if (mp.count(pair<int,int>(x,y))&&
			mp[pair<int,int>(x,y)]!=-1){
				del(x,y,mp[pair<int,int>(x,y)]);
				mp[pair<int,int>(x,y)]=-1;
			}
		if (tp!=-1){
			insert(x,y,tp);
			mp[pair<int,int>(x,y)]=tp;
		}
		printf("%d\n",count());
	}
}