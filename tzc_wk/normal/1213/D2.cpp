#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],cnt[200005][25],can[200005],ans=0x3f3f3f3f;
inline void calc(int x){
	int tmp=x,cur=0;
	while(tmp){
		cnt[tmp][cur]++;can[tmp]++;
		tmp>>=1;
		cur++;
	}
	cnt[0][cur]++;can[0]++;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)	calc(a[i]);
//	cout<<cnt[1][1]<<endl;
	for(int i=0;i<=200000;i++){
		if(can[i]>=k){
			int sum=0,tot=0;
			for(int j=0;j<=20;j++){
				while(cnt[i][j]&&tot<k){
					cnt[i][j]--;
					tot++;
					sum+=j;
				}
				if(tot==k)	break;
			}
//			cout<<i<<" "<<sum<<endl;
			ans=min(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}