#include<bits/stdc++.h>
#define EB emplace_back
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int T,n,pre[100005];
vector<int>st;
vector<int>LIS(vector<int>a){
	st.clear();
	vector<int>f(SZ(a));
	for(int i=0;i<SZ(a);++i){
		if(st.empty()||a[i]>st.back())st.EB(a[i]),f[i]=SZ(st),pre[a[i]]=0;
		else{
			auto it=lower_bound(st.begin(),st.end(),a[i]);
			pre[a[i]]=*it,*it=a[i];
			f[i]=it-st.begin()+1;
		}
	}
	int i=max_element(f.begin(),f.end())-f.begin(),cur=f[i],num=1e9;
	vector<int>b;
	for(;i>=0;--i){
		if(f[i]==cur&&a[i]<num){
			num=a[i];
			--cur;
			b.EB(a[i]);
		}
	}
	assert(cur==0);
	reverse(b.begin(),b.end());
	return b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vector<int>a(n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		vector<vector<int> >ans;
		while(SZ(a)){
			vector<int>b(LIS(a));
			if(SZ(b)*(SZ(b)+1)>2*SZ(a)){
				ans.PB(b);
				vector<int>aa;
				for(int i=0,j=0;i<SZ(a);++i){
					if(j>=SZ(b)||a[i]!=b[j])aa.EB(a[i]);
					if(j<SZ(b)&&a[i]==b[j])++j;
				}
				a=aa;
			}else{
				for(auto x:st){
					ans.PB({});
					for(int y=x;y;y=pre[y]){
						ans.back().PB(y);
					}
					reverse(ans.back().begin(),ans.back().end());
				}
				break;
			}
		}
		printf("%d\n",SZ(ans));
		for(auto&cur:ans){
			printf("%d ",SZ(cur));
			rep(i,0,SZ(cur)-1)printf("%d%c",cur[i],i==SZ(cur)-1?'\n':' ');
		}
	}
	return 0;
}
/*
1
9
6 2 1 8 4 9 3 7 5
*/