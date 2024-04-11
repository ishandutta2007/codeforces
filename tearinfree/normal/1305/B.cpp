#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,lli>;

char str[1010];
int n;

int main() {
	scanf("%s",str);
	n=strlen(str);

	int i=0,j=n-1,cnt=0;
	vector<int> ans;

	while(i<=j) {
		while(i<n && str[i]!='(') i++;
		while(j>=0 && str[j]!=')') j--;
		if(i>=j) break;

		ans.push_back(i+1);
		ans.push_back(j+1);
		i++;
		j--;
	}
	if(ans.size()==0) {
		puts("0");
		return 0;
	}
	printf("1\n%lu\n",ans.size());
	sort(ans.begin(),ans.end());
	for(auto &it:ans) printf("%d ",it);
	
	return 0;
}