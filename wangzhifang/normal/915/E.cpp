#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<int,int>mp;
int main(){
	int n,q,cl,cr,k,ans;
	scanf("%d%d",&n,&q);
	mp[n]=1,ans=n;
	for(; q; --q){
		scanf("%d%d%d",&cl,&cr,&k);
		map<int,int>::iterator it=mp.lower_bound(cl);
		while(it!=mp.end()){
			int l=it->second,r=it->first;
			if(cr<l)
				break;
			ans=ans-(min(r,cr)-max(l,cl)+1);
			mp.erase(it++);
			if(r>cr)
				mp[r]=cr+1;
			if(l<cl)
				mp[cl-1]=l;
		}
		if(k==2)
			mp[cr]=cl,ans+=cr-cl+1;
		printf("%d\n",ans);
	}
	return 0;
}