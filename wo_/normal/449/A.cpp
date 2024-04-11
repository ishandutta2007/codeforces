#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	long long N,M,K;
	cin>>N>>M>>K;
	if((N-1)+(M-1)<K){
		cout<<-1<<"\n";
		return 0;
	}
	int prev=N+2;
	long long ans=-1;
	for(int i=1;i<=N;i++){
		long long cx=N/i;
		if(cx==prev) break;
		prev=cx;
		int j=K+2-i;
		if(j<=0){
			cout<<ans<<"\n";
			return 0;
		}
		long long cy=M/j;
		ans=max(ans,cx*cy);
	}
	for(int x=prev;x>=1;x--){
		int a=N/x-1;
		int b=K-a;
		if(b<=0){
			int y=M;
			long long tmp=(long long)x*y;
			ans=max(ans,tmp);
			continue;
		}
		int y=M/(b+1);
		long long tmp=(long long)x*y;
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}