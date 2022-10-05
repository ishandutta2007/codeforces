#include<bits/stdc++.h>
using namespace std;
int n;
int a[210000];
int b[210000];
int cnt[210000];
int x;
vector<int> e[410000];
queue<int> q;
int d[410000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		int maxx=-1,x;
		for(int i=1;i<=n;i++)if(maxx<cnt[i]){
			x=i;
			maxx=cnt[i];
		}
		for(int i=1;i<=2*n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			if(a[i]!=x)e[i+n].push_back(a[i]);
			if(b[i]!=x)e[b[i]].push_back(i+n);
		}
		for(int i=1;i<=2*n;i++)d[i]=0;
		for(int i=1;i<=2*n;i++)for(int j : e[i])d[j]++;
		for(int i=1;i<=2*n;i++)if(d[i]==0)q.push(i);
		bool ok=1;
		int cnt=0;
		while(q.size()){
			cnt++;
			int o=q.front();
			q.pop();
			for(int i : e[o]){
				d[i]--;
				if(d[i]==0)q.push(i);
			}
		}
		if(cnt==2*n)printf("AC\n");
		else printf("WA\n");
	}
	return 0;
}