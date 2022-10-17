#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,k;
int a[maxn],c[maxn];
vector<int>now;
vector< vector<int> >ans;
multiset<int>s;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),s.insert(x);
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]);
	while(s.size()){
		int tot=1;
		now.push_back(*s.rbegin()),s.erase(--s.end());
		while(tot<c[1]){
			int L=0,R=k+1;
			while(L+1<R){
				int mid=(L+R)>>1;
				if(c[mid]<=tot)
					R=mid;
				else L=mid;
			}
			multiset<int>::iterator it=s.lower_bound(R);
			if(it==s.begin())
				break;
			it--,now.push_back(*it),s.erase(it),tot++;
		}
		reverse(now.begin(),now.end()),ans.push_back(now),now.clear();
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf("%d%c",ans[i][j],j==ans[i].size()-1? '\n':' ');
	}
	return 0;
}