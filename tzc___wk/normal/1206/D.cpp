#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],b[100005],dist[130][130],s[130][130],ans=LLONG_MAX,cnt;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)		b[++cnt]=a[i];
	}
	for(int i=1;i<=60;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>>(i-1)&1){
				cnt++;
			}
		}
		if(cnt>=3){
			puts("3");
			return 0;
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++){
			if(i!=j&&((b[i]&b[j])!=0))		s[i][j]=1,dist[i][j]=1;
			else							dist[i][j]=s[i][j]=0x3f3f3f3f;
		}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans=min(dist[i][j]+s[i][k]+s[k][j],ans);
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
	}
	cout<<((ans>=0x3f3f3f3f)?-1:ans)<<endl;
}