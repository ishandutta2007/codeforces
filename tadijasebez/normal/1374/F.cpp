#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		vector<int> a(n+1),ord(n+1),p(n+1);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]),ord[i]=i;
		sort(ord.begin()+1,ord.end(),[&](int i,int j){return a[i]<a[j];});
		for(int i=1;i<=n;i++)p[ord[i]]=i;
		vector<bool> was(n+1,false);
		int cyc=0;
		for(int i=1;i<=n;i++){
			if(was[i])continue;
			cyc++;
			for(int j=i;!was[j];j=p[j])was[j]=1;
		}
		bool ok=1;
		if((n-cyc)&1){
			ok=0;
			for(int i=2;i<=n;i++){
				if(a[ord[i]]==a[ord[i-1]]){
					p[ord[i]]=i-1;
					p[ord[i-1]]=i;
					swap(ord[i],ord[i-1]);
					ok=1;
					break;
				}
			}
		}
		if(ok){
			vector<int> ans;
			auto sw=[&](int i){
				ans.pb(i);
				swap(a[i],a[i+2]);
				swap(a[i+1],a[i+2]);
				swap(p[i],p[i+2]);
				swap(p[i+1],p[i+2]);
			};
			for(int i=1;i<=n-2;i++){
				int pos;
				for(int j=i;j<=n;j++)if(p[j]==i)pos=j;
				while(pos>i){
					if(pos>=i+2){
						pos-=2;
						sw(pos);
					}else{
						pos--;
						sw(pos);
						sw(pos);
					}
				}
			}
			assert(a[n]>=a[n-1]&&a[n-1]>=a[n-2]);
			printf("%i\n",ans.size());
			for(int i:ans)printf("%i ",i);
			printf("\n");
		}else printf("-1\n");
	}
	return 0;
}