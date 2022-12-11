#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N],b[N],dp1[N],dp2[N];
map<int,int>tag;
struct BIT{
	int ts[N];
	int ask(int x){
		int res=0;
		for(;x;x-=x&-x)res=max(ts[x],res);
		return res;
	}
	void add(int x,int d){
		for(;x<N;x+=x&-x)ts[x]=max(ts[x],d);
	}
}tr1,tr2,tr3;
int main(){
	scanf("%d",&n);
	vector<int>vec;
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		a[i]=x-i;
		b[i]=a[i]+1;
		vec.push_back(a[i]);
		vec.push_back(b[i]);
	}	
	stable_sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin()+1;
	for(int i=1;i<=n;i++)b[i]=lower_bound(vec.begin(),vec.end(),b[i])-vec.begin()+1;
	int res=0;
	for(int i=1;i<=n;++i){
		int val1=tr1.ask(a[i]),val2=tr2.ask(a[i]),val3=tr3.ask(b[i]);
		dp1[i]=val1+1;
		if(val2>0)dp2[i]=val2+1;
		if(i>2)dp2[i]=max(dp2[i],val3+1);
		tr1.add(a[i],dp1[i]);
		tr2.add(a[i],dp2[i]);
		if(i>1)tr3.add(a[i-1],dp1[i-1]);
		res=max(res,max(dp1[i],dp2[i]));
	}
	printf("%d\n",max(n-1-res,0));
	return 0;
}