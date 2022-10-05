#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1002],t[1002],l[1002],r[1002],tmp[1002]; 
bool ok[1002];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i]>>l[i]>>r[i];
	}
	for(int i=1;i<=n;i++)	a[i]=n-i+1;
	for(int i=1;i<=m;i++){
		if(t[i]==1){
			for(int j=l[i];j<r[i];j++){
				ok[j]=1;//ok[i]=1	sorted(a[i],a[i+1])
			}
		}
	}
	vector<pair<int,int> > v;
	int last=0;
	for(int i=1;i<=n;i++){
		if(!ok[i]&&ok[i-1]){
			v.push_back({last,i-1});
		}
		if(ok[i]&&!ok[i-1])	last=i;
	}
	for(int i=0;i<v.size();i++){
		int L=v[i].first,R=v[i].second;
		for(int j=1;j<=m;j++){
			if(!t[j]){
				if(l[j]>=L&&r[j]<=R+1){
					puts("NO");
					return 0;
				}
			}
		}
		memset(tmp,0,sizeof(tmp));
		for(int j=L;j<=R+1;j++){
			tmp[j-L+1]=a[j];
		}
		sort(tmp+1,tmp+R+1-L+2);
		for(int j=L;j<=R+1;j++){
			a[j]=tmp[j-L+1];
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)	cout<<a[i]<<" ";
	return 0;
}
/*
7 3
1 1 4
1 3 6
0 2 5
*/