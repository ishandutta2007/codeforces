#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <functional>

using namespace std;

int n;
map<int,int>mm;
int a[100500];
set< pair<int,int> > s;
int ra[100500][10];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)mm[a[i]]++;
	for (int i=0;i<n;i++)
		if (mm[a[i]]>0){
			s.insert(make_pair(-mm[a[i]],a[i]));
			mm[a[i]]=0;
	        }
	int ka=0;
	while (1){
		pair<int,int> aa,bb,cc;
		while ((!s.empty())){
			set<pair<int,int> >::iterator it=s.end();
			it--;
			if ((*it).first!=0)break;
			s.erase(it);
		}
		if (s.size()<3)break;
		aa=(*s.begin());
		s.erase(s.begin());
		bb=(*s.begin());
		s.erase(s.begin());
		cc=(*s.begin());
		s.erase(s.begin());
		ra[ka][0]=aa.second;
		ra[ka][1]=bb.second;
		ra[ka][2]=cc.second;
		ka++;
		aa.first++;
		bb.first++;
		cc.first++;
		s.insert(aa);
		s.insert(bb);
		s.insert(cc);
	}
	printf("%d\n",ka);
	for (int i=0;i<ka;i++){
		sort(ra[i],ra[i]+3);
		printf("%d %d %d\n",ra[i][2],ra[i][1],ra[i][0]);
	}
}