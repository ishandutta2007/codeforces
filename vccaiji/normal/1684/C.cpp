#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210000];
int b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n*m;i++)b[i]=a[i];
		for(int i=1;i<=n;i++)sort(b+(i-1)*m+1,b+i*m+1);
		bool r=1;
		vector<int> s;
		for(int i=1;i<=n*m;i++){if(a[i]!=b[i]){
			r=0;
			if(s.size()<=10)s.push_back(i);
		}
		}
		if(r){
			cout<<"1 1\n";
			continue;
		}
		int k1=(s[0]-1)%m+1,k2=(s[1]-1)%m+1;
		for(int i=1;i<=n;i++)swap(a[(i-1)*m+k1],a[(i-1)*m+k2]);
		r=1;
		for(int i=1;i<=n*m;i++)if(a[i]!=b[i])r=0;
		if(r){
			cout<<k1<<' '<<k2<<"\n";
		}
		else cout<<"-1\n";
	}
	return 0;
}