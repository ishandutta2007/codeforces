#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

vector<string> a, b;
int n, i, ans;
bool cmp(string i,string j){
	if(i.size()==j.size()) return i<j;
	else return i.size()<j.size();
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		a.push_back(""), cin >> a.back();
	for(i=1;i<=n;i++)
		b.push_back(""), cin >> b.back();
	for(i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]){
				a.erase(a.begin()+i); i--;
				b.erase(b.begin()+j);
				break;
			}
		}
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++)
			if(a[i][j]!=b[i][j]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}