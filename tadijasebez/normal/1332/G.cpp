#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
set<int> lo,hi,mx,nmx,mn,nmn,ost;
int cnt[N],a[N],l[N],r[N];
vector<int> qs[N],ans[N];
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=q;i++)scanf("%i %i",&l[i],&r[i]),qs[l[i]].pb(i);
	vector<int> ans3,ans4;
	for(int i=n;i>=1;i--){
		for(int j;hi.size()&&a[j=*hi.begin()]<a[i];nmx.insert(j),cnt[j]++,hi.erase(j))if(cnt[j]==1)ost.insert(j);
		for(int j;lo.size()&&a[j=*lo.begin()]>a[i];nmn.insert(j),cnt[j]++,lo.erase(j))if(cnt[j]==1)ost.insert(j);
		for(int j;mx.size()&&a[j=*mx.begin()]<=a[i];mx.erase(j));
		for(int j;mn.size()&&a[j=*mn.begin()]>=a[i];mn.erase(j));
		if(mx.size()&&mn.size()){
			auto it4=ost.upper_bound(max(*mx.begin(),*mn.begin()));
			if(it4!=ost.end()&&(ans4.empty()||ans4.back()>*it4)){
				ans4={i,*prev(mn.lower_bound(*it4)),*prev(mx.lower_bound(*it4)),*it4};
				if(ans4[1]>ans4[2])swap(ans4[1],ans4[2]);
			}
		}
		if(nmx.size()&&mx.size()){
			auto it3=nmx.upper_bound(*mx.begin());
			if(it3!=nmx.end()&&(ans3.empty()||ans3.back()>*it3))
				ans3={i,*prev(mx.lower_bound(*it3)),*it3};
		}
		if(nmn.size()&&mn.size()){
			auto it3=nmn.upper_bound(*mn.begin());
			if(it3!=nmn.end()&&(ans3.empty()||ans3.back()>*it3))
				ans3={i,*prev(mn.lower_bound(*it3)),*it3};
		}
		for(int j:qs[i]){
			if(ans4.size()&&ans4.back()<=r[j])ans[j]=ans4;
			else if(ans3.size()&&ans3.back()<=r[j])ans[j]=ans3;
		}
		hi.insert(i);
		lo.insert(i);
		mx.insert(i);
		mn.insert(i);
	}
	for(int i=1;i<=q;i++){
		printf("%i\n",ans[i].size());
		for(int j=0;j<ans[i].size();j++)printf("%i%c",ans[i][j],j+1==ans[i].size()?'\n':' ');
	}
	return 0;
}