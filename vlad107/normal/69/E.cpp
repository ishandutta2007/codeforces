#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

int n,m,a[100500];
std::set <int,std::greater<int> >q;
std::map <int,int>kol;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	kol.clear();
	for (int i=0;i<m;i++){
		kol[a[i]]++;
		if (kol[a[i]]==1)q.insert(a[i]);
		if (kol[a[i]]==2)q.erase(a[i]);
	}
	if (q.empty())
		puts("Nothing");
	else printf("%d\n",*q.begin());
	for (int i=m;i<n;i++){
		kol[a[i]]++;
		if (kol[a[i]]==1)q.insert(a[i]);
		if (kol[a[i]]==2)q.erase(a[i]);
		kol[a[i-m]]--;
		if (kol[a[i-m]]==1)q.insert(a[i-m]);
		if (kol[a[i-m]]==0)q.erase(a[i-m]);
		if (q.empty())
			puts("Nothing");
		else printf("%d\n",*q.begin());
	}
}