#include <bits/stdc++.h>
using namespace std;
int n,r,a[100005];
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n>>r;
		for(int i=1;i<=n;i++)	cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0,num=0;
		n=unique(a+1,a+n+1)-a-1;
		for(int i=n;i>=1;i--){
			if(a[i]-num<=0)	break;
            ans++;
            num+=r;
		}
		cout<<ans<<endl;
	}
}
/*
1
7 2
5 5 2 4 7 6 2

1
9 8
1 9 6 10 8 8 6 10 3
*/