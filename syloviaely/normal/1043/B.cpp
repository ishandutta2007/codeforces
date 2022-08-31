#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,A[1100];
vector<int> ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=n;i;i--) A[i]-=A[i-1];
	for (int l=1;l<=n;l++){
		int flag=0;
		for (int i=1;i<=n;i++)
			if (A[i]!=A[(i-1)%l+1]) flag=1;
		if (flag==0) ans.pb(l);
	}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	puts("");
}