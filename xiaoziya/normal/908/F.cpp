#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,flg;
int x[maxn],t[maxn];
long long ans;
string s;
void solve(int l,int r){
	int l1=x[l],l2=x[l];
	vector<int>v1,v2;
	for(int i=l+1;i<=r-1;i++){
		if(t[i]==1)
			v1.push_back(x[i]-l1),l1=x[i];
		if(t[i]==2)
			v2.push_back(x[i]-l2),l2=x[i];
	}
	v1.push_back(x[r]-l1),v2.push_back(x[r]-l2);
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
	long long res=(x[r]-x[l])*3ll-v1.back()-v2.back();
	res=min(res,(x[r]-x[l])*2ll);
	ans+=res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]),cin>>s,t[i]=s=="G"? 0:(s=="B"? 1:2);
		if(t[i]==0)
			flg=1;
	}
	if(flg==0){
		int l1=0,l2=0,f1=0,f2=0;
		for(int i=1;i<=n;i++){
			if(t[i]==1){
				if(f1)
					ans+=x[i]-l1;
				l1=x[i],f1=1;
			}
			else{
				if(f2)
					ans+=x[i]-l2;
				l2=x[i],f2=1;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	int mn0=1e9,mx0=-1e9,mn1=1e9,mx1=-1e9,mn2=1e9,mx2=-1e9;
	for(int i=1;i<=n;i++){
		if(t[i]==0)
			mn0=min(mn0,x[i]),mx0=max(mx0,x[i]);
		if(t[i]==1)
			mn1=min(mn1,x[i]),mx1=max(mx1,x[i]);
		if(t[i]==2)
			mn2=min(mn2,x[i]),mx2=max(mx2,x[i]);
	}
	if(mn1<=mn0)
		ans+=mn0-mn1;
	if(mx1>=mx0)
		ans+=mx1-mx0;
	if(mn2<=mn0)
		ans+=mn0-mn2;
	if(mx2>=mx0)
		ans+=mx2-mx0;
	int lst=-1;
	for(int i=1;i<=n;i++)
		if(t[i]==0){
			if(lst!=-1)
				solve(lst,i);
			lst=i;
		}
	printf("%lld\n",ans);
	return 0;
}