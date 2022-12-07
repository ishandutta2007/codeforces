#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
int n,m1,m2;
int co1[N],co2[N];
int ansx[N],ansy[N];
void Updateee(int c,int co,int cn,int id,int tp);
struct Node{
	set<int> re,re2;
	set<int> S[N];
	map<int,int> mp[N];
	void init(){
		for (int i=1;i<=n;i++){
			re.insert(i);
			S[i].insert(i);
			mp[i][i]=i;
		}
	}
	void Merge(int x,int y,int *co1,int *co2,int tp){
		if (S[co1[x]].size()>S[co1[y]].size()) swap(x,y);
		int co=co1[x],cn=co1[y];
		re.erase(co);
		if (mp[co].size()>=2) re2.erase(co);
		if (mp[cn].size()>=2) re2.erase(cn);
		for (auto i:S[co]){
			Updateee(co2[i],co1[i],co1[y],i,tp);
			co1[i]=co1[y];
			S[co1[i]].insert(i);
			mp[co1[i]][co2[i]]=i;
		}
		if (mp[cn].size()>=2) re2.insert(cn);
	}
	void Update(int c,int co,int cn,int id){
		if (mp[c].size()>=2) re2.erase(c);
		mp[c].erase(co); mp[c][cn]=id;
		if (mp[c].size()>=2) re2.insert(c);
	}
	void find(int &x,int &y){
		if (!re2.size()){
			auto it=re.begin();
			x=(*it); ++it; y=*it;
			x=(*mp[x].begin()).second;
			y=(*mp[y].begin()).second;
		}
		else{
			auto it=re2.begin();
			int a=*it;
			it=re.begin();
			for (;*it==a;++it);
			int b=*it;
			bool found=0;
			for (auto A:mp[a]){
				if (found) break;
				for (auto B:mp[b]){
					if (found) break;
					if (A.first!=B.first){
						x=A.second;
						y=B.second;
						found=1;
					}
				}
			}
		}
	}
}T1,T2;
void Updateee(int c,int co,int cn,int id,int tp){
	if (tp==0) T2.Update(c,co,cn,id);
	else T1.Update(c,co,cn,id);
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=1;i<=n;i++) co1[i]=co2[i]=i;
	T1.init(); T2.init();
	for (int i=1;i<=m1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		T1.Merge(x,y,co1,co2,0);
	}
	for (int i=1;i<=m2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		T2.Merge(x,y,co2,co1,1);
	}
	for (;T1.re.size()!=1&&T2.re.size()!=1;){
		int x,y;
		if (T1.re.size()<=T2.re.size())
			T1.find(x,y);
		else
			T2.find(x,y);
		T1.Merge(x,y,co1,co2,0);
		T2.Merge(x,y,co2,co1,1);
		ansx[++*ansx]=x;
		ansy[++*ansy]=y;
	}
	printf("%d\n",*ansx);
	for (int i=1;i<=*ansx;i++)
		printf("%d %d\n",ansx[i],ansy[i]);
}