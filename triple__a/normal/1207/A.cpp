#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--){
		int a,b[3],c[3];
		cin>>a>>b[0]>>b[1]>>c[0]>>c[1];
		if (c[0]<c[1]){
			swap(b[0],b[1]);
			swap(c[0],c[1]);
		}
		int ans=0,cnt=0;
		while (a>=2&&cnt<2){
			while (a>=2&&b[cnt]>=1){
				ans+=c[cnt];
				b[cnt]--;
				a-=2;
			}
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}