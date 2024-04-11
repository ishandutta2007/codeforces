#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
int n,cnt;
char s[100005];
set<int> S[2];
vector<int> ans,vec;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n)
		S[s[i]=='L'].insert(i);
	for (;!S[0].empty()||!S[1].empty();){
		++cnt;
		if (S[0].empty()){
			ans.PB(*S[1].begin());
			S[1].erase(*S[1].begin());
			continue;
		}
		if (S[1].empty()){
			ans.PB(*S[0].begin());
			S[0].erase(*S[0].begin());
			continue;
		}
		int tp=*S[0].begin()>*S[1].begin();
		if (cnt==1){
			if (S[0].size()<S[1].size()) tp=1;
			if (S[0].size()>S[1].size()) tp=0;
		}
		vec.resize(0);
		int lasv=0;
		for (;;){
			set<int>::iterator it;
			it=S[tp].lower_bound(lasv+1);
			if (it==S[tp].end()) break;
			vec.PB(*it); lasv=*it;
			S[tp].erase(it); tp^=1;
		}
		if (S[tp^1].size()&&(!S[tp].size()||*S[tp^1].begin()<*S[tp].begin()))
			S[tp^1].insert(vec.back()),vec.pop_back();
		For(i,0,vec.size()-1) ans.PB(vec[i]);
	}
	printf("%d\n",cnt-1);
	For(i,0,n-1) printf("%d ",ans[i]);
}