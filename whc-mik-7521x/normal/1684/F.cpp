#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],pd[N];
struct BIT{
	int ts[N];
	void init(){
		for(int i=0;i<n;i++)ts[i]=-1;
	}
	void add(int x,int d){
		for(;x<n;x|=(x+1))ts[x]=max(ts[x],d);
	}
	int ask(int x){
		int ans=-1;
		for(;x>=0;x=(x&(x+1))-1)ans=max(ans,ts[x]);
		return ans;
	}
}tr;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		map<int,vector<int>>mp;
		vector<pair<int,int>>b;
		set<int>s;
		tr.init();
		b.resize(m);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)mp[a[i]].push_back(i);
		for(int i=0;i<m;i++)scanf("%d%d",&b[i].first,&b[i].second),tr.add(--b[i].first,--b[i].second);
		int l=n;
		for(int r=n-1;r>=0;r--){
			while(l-1>=0&&!s.count(a[l-1])){
				l--;
				s.insert(a[l]);
			}
			pd[r]=l;
			s.erase(a[r]);
		}
		int ansr=-1;
		for(int i=0;i<m;i++){
			int l=b[i].first,r=b[i].second;
			if(pd[r]<=l)continue;
			ansr=max(ansr,pd[r]-1);
		}
		if(ansr==-1){
			puts("0");
		}
		else{
			int ans=ansr+1;
			for(int l=0;l+1<n;l++){
				if(mp[a[l]][0]!=l){
					int num=lower_bound(mp[a[l]].begin(),mp[a[l]].end(),l)-mp[a[l]].begin()-1;
					int pr=mp[a[l]][num];
					if(tr.ask(pr)>=l){
						break;
					}
				}
				int num=upper_bound(mp[a[l]].begin(),mp[a[l]].end(),ansr)-mp[a[l]].begin();
				if(num!=(int)mp[a[l]].size()){
					int nxt=mp[a[l]][num];
					if(tr.ask(l)>=nxt){
						ansr=nxt;
					}
				}
				ansr=max(ansr,l+1);
				ans=min(ans,ansr-l);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}