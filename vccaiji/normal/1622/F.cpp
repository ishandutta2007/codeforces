#include<bits/stdc++.h>
using namespace std;
int isp[1100000];
int tot=0;
int p[260];
map<long long,int> mp;
int a[1100000];
int b[1100000];
vector<int> pr[1100000];
long long h[1100000];
long long v[1100000];
int main(){
	for(int i=2;i<=1000000;i++)isp[i]=1;
	for(int i=2;i<=1000000;i++){
		if(isp[i]){
			long long val=1ll*rand()*10000000000000ll+rand()*5+rand(); 
			for(int j=i;j<=1000000/i;j++)isp[i*j]=0;
			for(int k=1;k<=1000000/i;k*=i){
				int u=k*i;
				for(int j=1;j<=1000000/u;j++){
					pr[u*j].push_back(i);
					h[u*j]^=val;
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++)if((n+1-i)&1){
		for(int j=0;j<pr[i].size();j++)a[pr[i][j]]^=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<pr[i].size();j++)b[pr[i][j]]^=1;
	}*/
	int n;
	cin>>n;
	long long hh=0;
	for(int i=2;i<=n;i++)h[i]^=h[i-1];
	for(int i=1;i<=n;i++)hh^=h[i];
	if(hh==0){
		cout<<n<<endl;
		for(int i=1;i<=n;i++)cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(h[i]==hh){
			cout<<n-1<<endl;
			for(int j=1;j<i;j++)cout<<j<<' ';
			for(int j=i+1;j<=n;j++)cout<<j<<' ';
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		mp[h[i]^hh]=i;
		if(mp.count(h[i])){
			int j=mp[h[i]];
			cout<<n-2<<endl;
			for(int k=1;k<min(i,j);k++)cout<<k<<' ';
			for(int k=min(i,j)+1;k<max(i,j);k++)cout<<k<<' ';
			for(int k=max(i,j)+1;k<=n;k++)cout<<k<<' ';
			cout<<endl;
			return 0;
		}
	}
	if(n&1)n--;
	cout<<n-2<<endl;
	for(int i=1;i<=n;i++){
		if((i!=2)&&(i!=n/2))cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}