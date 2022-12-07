#include<bits/stdc++.h>

using namespace std;
int n,m,Q;
vector<pair<int,int> > op,nop;
set<pair<int,int> > S;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		S.insert(pair<int,int>(x,y));
	}
	op.push_back(pair<int,int>(1,1));
	int ans=0;
	for (;;){
		if (op[0]==pair<int,int>(n,m)){
			printf("%d\n",ans);
			return 0;
		}
		nop.resize(0);
		for (auto i:op){
			int sum=i.first+i.second;
			if (S.find(i)!=S.end()) ++sum;
			nop.push_back(pair<int,int>(i.first,min(m,sum)));
			nop.push_back(pair<int,int>(min(n,sum),i.second));
		}
		sort(nop.begin(),nop.end());
		int t=0;
		for (int i=1;i<nop.size();i++){
			for (;t>=0&&nop[t].first<=nop[i].first&&
						nop[t].second<=nop[i].second;--t);
			nop[++t]=nop[i];
		}
		nop.resize(t+1);
		swap(nop,op);
		++ans;
	}
}