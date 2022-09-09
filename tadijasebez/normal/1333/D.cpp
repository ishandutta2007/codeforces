#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=3050;
char s[N];
int a[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	vector<vector<int>> ans;
	for(int i=1;i<=n;i++){
		a[i]=s[i]=='L';
	}
	int mx=0;
	while(1){
		vector<int> now;
		for(int i=1;i<n;i++){
			if(a[i]==0 && a[i+1]==1){
				now.pb(i);
			}
		}
		for(int i:now)swap(a[i],a[i+1]);
		if(now.empty())break;
		mx+=now.size();
		ans.pb(now);
	}
	int mn=ans.size();
	if(k<mn || k>mx)printf("-1\n");
	else{
		k-=ans.size();
		for(auto now:ans){
			while(now.size()>1 && k>0){
				printf("1 %i\n",now.back());
				now.pop_back();
				k--;
			}
			printf("%i ",now.size());
			for(int i:now)printf("%i ",i);
			printf("\n");
		}
	}
	return 0;
}