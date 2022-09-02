#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,tot;
char s[N];
vector<int>ans;
set<int>s1,s2;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n){
		if(s[i]=='L')s1.insert(i);
		else s2.insert(i);
	}
	s1.insert(INF),s2.insert(INF);
	if(MP(-SZ(s1),*s1.begin())>MP(-SZ(s2),*s2.begin()))swap(s1,s2);
	int go=*s1.begin();
	rep(i,1,n){
		if(i&1){
			if(go==INF||(*s2.lower_bound(go)==INF&&*s1.begin()!=go&&*s1.begin()<*s2.begin())){
				++tot;
				go=*s1.begin();
			}
			s1.erase(go);
			ans.PB(go);
			go=*s2.lower_bound(go);
		}else{
			if(go==INF||(*s1.lower_bound(go)==INF&&*s2.begin()!=go&&*s2.begin()<*s1.begin())){
				++tot;
				go=*s2.begin();
			}
			s2.erase(go);
			ans.PB(go);
			go=*s1.lower_bound(go);
		}
	}
	printf("%d\n",tot);
	for(auto x:ans)printf("%d ",x);
	return 0;
}