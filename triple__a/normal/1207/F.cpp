#include<bits/stdc++.h>
using namespace std;
 
const int md=407;
const int maxn=500007;
 
int sum[md+7][md+7];
int ans[maxn];
int n;
 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		int op;
		cin>>op;
		if (op==1){
			int x,y;
			cin>>x>>y;
			for (int i=1;i<=md;++i){
				sum[i][x%i]+=y;
			}
			ans[x]+=y;
		}
		else{
			int x,y;
			cin>>x>>y;
			if (x<=md){
				cout<<sum[x][y]<<endl;
			}
			else{
				int calc=0;
				for (int i=y;i<=maxn;i+=x){
					calc+=ans[i];
				}
				cout<<calc<<endl;
			}
		}
	}
	return 0;
}