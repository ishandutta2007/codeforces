#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXB=320;
const int MAXN=1e5+15;
int n,a[MAXN];
deque<int> d[MAXB];
int num[MAXB][MAXN];
int block,pos[MAXN];
int ans;
void update(int l,int r){
	int p=pos[l],q=pos[r];
//	cout<<"p="<<p<<"\tq="<<q<<endl;
	if(p==q){
		deque<int>::iterator it=d[p].begin()+(r-1)%block;
		int tmp=*it;
		d[p].erase(d[p].begin()+(r-1)%block);
		d[p].insert(d[p].begin()+((l-1)%block),tmp);
	}
	else{
		deque<int>::iterator it=d[q].begin()+(r-1)%block;
		int tmp=*it;
//		cout<<tmp<<endl;
		num[q][tmp]--;
		d[q].erase(d[q].begin()+(r-1)%block);
		for(int i=p;i<q;i++){
			int x=d[i].back();
			d[i].pop_back();
			num[i][x]--;
			d[i+1].push_front(x);
			num[i+1][x]++;
		}
		d[p].insert(d[p].begin()+((l-1)%block),tmp);
		num[p][tmp]++;
	}
}
void query(int l,int r,int k){
	ans=0;
	int p=pos[l],q=pos[r];
	if(p==q){
		for(deque<int>::iterator it=d[p].begin()+(l-1)%block;it<=d[p].begin()+(r-1)%block;it++){
			if((*it)==k){
				ans++;
			}
		}
	}
	else{
		for(int i=p+1;i<=q-1;i++)	ans+=num[i][k];
		for(deque<int>::iterator it=d[p].begin()+(l-1)%block;it!=d[p].end();it++){
			if((*it)==k){
				ans++;
			}
		}
		for(deque<int>::iterator it=d[q].begin();it<=d[q].begin()+(r-1)%block;it++){
			if((*it)==k){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(;block*block<=n;block++);
	for(int i=1;i<=n;i++)	pos[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++){
		int s=pos[i];
		d[s].push_back(a[i]);
		num[s][a[i]]++;
	}
	int T;cin>>T;
	while(T--){
		int type;cin>>type;
		if(type==1){
			int _l,_r;
			cin>>_l>>_r;
			int l=(_l+ans-1)%n+1,r=(_r+ans-1)%n+1;
			if(l>r)	swap(l,r);
			update(l,r);
		}
		else{
			int _l,_r,_k;
			cin>>_l>>_r>>_k;
			int l=(_l+ans-1)%n+1,r=(_r+ans-1)%n+1,k=(_k+ans-1)%n+1;
			if(l>r)	swap(l,r);
			query(l,r,k);
		}
	}
}