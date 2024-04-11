#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cstring>

using namespace std;

int n;
char str[1000100];

int le[1000100],ri[1000100];

set<int> tr;
bool upd(int cur) {
	if(cur==0 || cur==n+1) return false;
	if(cur!=1 && le[cur]!=0 && str[cur]!=str[le[cur]]) return true;
	else if(cur!=n && ri[cur]!=n+1 && tr.find(ri[cur])==tr.end() && str[cur]!=str[ri[cur]]) return true;
	return false;
}
int main() {
	scanf("%s",str+1);
	n=strlen(str+1);
	
	for(int i=1;i<=n;i++) {
		if(i!=1 && str[i]!=str[i-1]) tr.insert(i);
		else if(i!=n && str[i]!=str[i+1]) tr.insert(i);
		le[i]=i-1; ri[i]=i+1;
	}

	for(int c=0;;c++) {
		if(tr.empty()) {
			printf("%d\n",c);
			break;
		}
		vector<int> a;
		for(auto &it:tr) a.push_back(it);
		for(auto &it:a) {
			ri[le[it]]=ri[it];
			le[ri[it]]=le[it];
			if(upd(le[it])) tr.insert(le[it]);
			if(upd(ri[it])) tr.insert(ri[it]);
			tr.erase(it);
		}
	}

	return 0;
}