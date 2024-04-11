#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500];
ll m1,m2,f1[200500],f2[200500],g1[200500],g2[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		m1=m2=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			int x=a[i],y=1;
			while(!(x%m)){
				x/=m;y*=m;
			}
			if(f1[m1]==x){
				g1[m1]+=y;
			}
			else{
				f1[++m1]=x;
				g1[m1]=y;
			}
		}
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>b[i];
			int x=b[i],y=1;
			while(!(x%m)){
				x/=m;y*=m;
			}
			if(f2[m2]==x){
				g2[m2]+=y;
			}
			else{
				f2[++m2]=x;
				g2[m2]=y;
			}
		}
		if(m1!=m2){
			cout<<"No\n";continue;
		}
		for(i=1;i<=m1;i++){
			if(f1[i]!=f2[i]||g1[i]!=g2[i]){
				cout<<"No\n";goto aaa;
			}
		}
		cout<<"Yes\n";
		aaa:;
	}
}