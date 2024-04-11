#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
const int maxn=200005;
int n,m,ans;
set< pair<int,int> >s[maxn];
vector<int>v[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),v[x].push_back(i);
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			int k=j;
			while(k+1<v[i].size()&&v[i][k+1]==v[i][k]+1)
				k++;
			s[i].insert(make_pair(v[i][j],v[i][k])),j=k,ans++;
		}
	}
	printf("%d\n",ans-1);
	for(int t=1,a,b;t<m;t++){
		scanf("%d%d",&a,&b);
		int flg=0;
		if(s[a].size()<s[b].size())
			flg=1,swap(a,b);
		for(set< pair<int,int> >::iterator it=s[b].begin();it!=s[b].end();it++){
			int l=it->first,r=it->second;
			set< pair<int,int> >::iterator p=s[a].lower_bound(*it);
			if(p!=s[a].begin()){
				p--;
				if(p->second==l-1)
					l=p->first,s[a].erase(p),ans--;
			}
			p=s[a].upper_bound(*it);
			if(p!=s[a].end()&&p->first==r+1)
				r=p->second,s[a].erase(p),ans--;
			s[a].insert(make_pair(l,r));
		}
		s[b].clear();
		if(flg==1)
			swap(s[a],s[b]);
		printf("%d\n",ans-1);
	}
	return 0;
}