#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[210000];
int l[210000],r[210000];
int t[210000];
int s[210000];
int cnt1[210000],cnt2[210000];
map<int,int> mp;
int main(){
	int _;
	cin>>_;
	while(_--){
		mp.clear();
		cin>>n>>m;
		int tot=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(mp.count(a[i]))a[i]=mp[a[i]];
			else mp[a[i]]=++tot,a[i]=tot;
		}
		for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<=n;i++)t[i]=i;
		for(int i=1;i<=m;i++)t[l[i]]=max(t[l[i]],r[i]);
		for(int i=1;i<n;i++)t[i+1]=max(t[i+1],t[i]);
		t[0]=0;
		
		for(int i=1;i<=n;i++)s[i]=i;
		for(int i=1;i<=m;i++)s[r[i]]=min(s[r[i]],l[i]);
		for(int i=n-1;i;i--)s[i]=min(s[i+1],s[i]);
		s[n+1]=n+1;
		int rr=n+1;
		for(int i=1;i<=n;i++)cnt1[i]=cnt2[i]=n+1;
		for(int i=n;i>=1;i--){
			for(int j=s[i+1]-1;j>=s[i];j--){
				cnt2[a[j]]=cnt1[a[j]];
				cnt1[a[j]]=j;
				if(cnt2[a[j]]<=i)rr=min(rr,cnt2[a[j]]);
			}
		}
		int r=0,ans;
		for(int i=1;i<=n;i++)cnt1[i]=cnt2[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=t[i-1]+1;j<=t[i];j++){
				cnt2[a[j]]=cnt1[a[j]];
				cnt1[a[j]]=j;
				if(cnt2[a[j]]>=i)r=max(r,cnt2[a[j]]);
			}
		}
		for(int i=1;i<=n;i++)cnt1[i]=cnt2[i]=0;
		ans=r;
		for(int i=1;i<min(rr,n+1);i++){
			for(int j=t[i-1]+1;j<=t[i];j++){
				cnt2[a[j]]=cnt1[a[j]];
				cnt1[a[j]]=j;
			}
			r=max(r,i);
			if(cnt1[a[i]]>i)r=max(r,cnt1[a[i]]);
			ans=min(ans,r-i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
10 5
1 1 1 1 2  2 3 4 5 1
1 4
2 5
1 7
4 8
1 5
*/