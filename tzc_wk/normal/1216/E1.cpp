#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,x;
int cnt(int t){
	int num=9,sum=0,mx=10,mn=0;
	for(int i=1;i<=10;i++){
		if(t<mx){
			return sum+(t-mn)*i;
		}
		sum+=num*i;
		mx*=10;num*=10;
		mn=mn*10+9;
	}
}
int digall(int t){
	int num=9,sum=0,mx=10,mn=1;
	for(int i=1;i<=10;i++){
		if(t<mx){
			return sum+(cnt(t)+cnt(mn))*(t-mn+1)/2;
		}
		sum+=(cnt(mn)+cnt(mx-1))*num/2;
		mx*=10;num*=10;mn*=10;
	}
}
inline void solve(){
	cin>>x;
	int l=0,r=1e9,mn1=0,t1=0,mn2=0,t2=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(digall(mid)<x)	l=mid+1,mn1=mid,t1=mid;
		else				r=mid-1;
	}
	mn1=x-digall(mn1);
//	cout<<t1<<" "<<mn1<<endl;
	l=0,r=t1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(cnt(mid)<mn1)	l=mid+1,mn2=mid,t2=mid;
		else				r=mid-1;
	}
	mn2=mn1-cnt(mn2);
	t2++;
//	cout<<t2<<" "<<mn2<<endl;
	int dignum=(int)log10(t2)+1;
	for(int i=1;i<=dignum-mn2;i++)	t2/=10;
	cout<<t2%10<<endl;
}
signed main(){
	cin>>T;
	while(T--)	solve();
	return 0;
}