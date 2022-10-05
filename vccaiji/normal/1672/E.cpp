#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int l=1,r=100000000;
		for(;l<r;){
			int md=(l+r)/2;
			cout<<"? "<<md<<endl;
			int x;
			cin>>x;
			if(x==1)r=md;
			else l=md+1;
		} 
		int ans=l;
		for(int i=2;i<=n;i++){
			int w=ans/i;
			if(w>0){
				cout<<"? "<<w<<endl;
				int x;
				cin>>x;
				if(x==i)ans=min(ans,w*i);
			}
		}
		cout<<"! "<<ans<<endl;
	}
	return 0;
}