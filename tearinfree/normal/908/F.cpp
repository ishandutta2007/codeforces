#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long lli;

int n,arr[300000];
char ch[300000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %c",arr+i,ch+i);

	lli res=0;
	int i=0;
	int pr[2]={-1,-1};
	for(;i<n && ch[i]!='G';i++) {
		if(ch[i]=='R') {
			if(pr[0]!=-1) res+=arr[i]-pr[0];
			pr[0]=arr[i];
		}
		else {
			if(pr[1]!=-1) res+=arr[i]-pr[1];
			pr[1]=arr[i];
		}
	}
	if(i==n) {
	    printf("%lld\n",res);
	    return 0;
		int mx=1e9;
		pr[0]=pr[1]=-1;
		for(int i=0;i<n;i++) {
			if(ch[i]=='R') {
				if(pr[1]!=-1) mx=min(mx,arr[i]-pr[1]);
				pr[0]=arr[i];
			}
			else {
				if(pr[0]!=-1) mx=min(mx,arr[i]-pr[0]);
				pr[1]=arr[i];
			}
		}
		if(pr[0]==-1 || pr[1]==-1) mx=0;
		printf("%lld\n",res+mx);
		return 0;
	}
	if(pr[0]!=-1)res+=arr[i]-pr[0];
	if(pr[1]!=-1)res+=arr[i]-pr[1];

	for(;i<n-1;) {
		vector<int> t[2];
		t[0].push_back(arr[i]);
		t[1].push_back(arr[i]);
		int j;
		for(j=i+1;j<n;j++) {
			if(ch[j]=='G') break;
			if(ch[j]=='R') {
				t[0].push_back(arr[j]);
			}
			else t[1].push_back(arr[j]);
		}
		if(j==n) {
			res+=t[0].back()-t[0][0];
			res+=t[1].back()-t[1][0];
			break;
		}
		t[0].push_back(arr[j]);
		t[1].push_back(arr[j]);
		lli msum=0;
		for(int k=0;k<2;k++) {
			int mx=0;
			for(int ii=0;ii<t[k].size()-1;ii++) mx=max(mx,t[k][ii+1]-t[k][ii]);
			msum+=mx;
		}
		msum = (arr[j]-arr[i])*3ll - msum;
		res+=min(msum, (arr[j]-arr[i])*2ll);
		i=j;
	}
	printf("%lld\n",res);
	return 0;
}