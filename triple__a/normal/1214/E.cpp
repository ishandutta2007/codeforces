#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;

int n,d[maxn],p[maxn];
deque<int> dq;

bool cmp(const int &u,const int &v){
	return d[u]>d[v];
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>d[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<n;++i){
		cout<<p[i]*2<<" "<<p[i+1]*2<<endl;
	}
	for (int i=1;i<=n;++i){
		dq.push_back(p[i]*2);
	}
	while (!dq.empty()){
		
		int u=dq.front();
		if (u%2){
			dq.pop_front();
			continue;
		}
		int pos=d[u>>1]-1;
//		cout<<pos<<endl;
		cout<<u-1<<" "<<dq[pos]<<endl;
		if (pos+1==dq.size()){
			dq.push_back(u-1);
		}
		dq.pop_front();
	}
	return 0;
}