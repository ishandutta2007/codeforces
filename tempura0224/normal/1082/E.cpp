#include<iostream>
using namespace std;
int cnt[1<<20],mi[1<<20],n,c,a,ans;
int main(){
	cin>>n>>c;
	while(n--){
		cin>>a;
		mi[a]=min(mi[a],cnt[a]-cnt[c]);
		++cnt[a];
		ans=max(cnt[a]-cnt[c]-mi[a],ans);
	}
	cout<<ans+cnt[c]<<endl;
	return 0;
}