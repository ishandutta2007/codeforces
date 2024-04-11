#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
int n,B,x[N],sum[N],top,st[N];char s[N];ll ans;
int main(){
	cin>>s+1,n=strlen(s+1),B=sqrt(n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]=='1');
	for(int i=1;i<=B;++i){
		for(int j=0;j<=n;++j)x[j]=i*sum[j]-j;
		sort(x,x+1+n);
		for(int j=0;j<=n;){
			int k=j+1;
			while(k<=n&&x[k]==x[j])++k;
			ans+=1ll*(k-j)*(k-j-1)/2;
			j=k;
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='1')st[++top]=i;
		for(int j=top;j>=1&&(top-j+1)*(B+1)<=i;--j){
			int l=max(i-st[j]+1,(top-j+1)*(B+1)),r=i-st[j-1];
			if(l<=r)ans+=r/(top-j+1)-(l-1)/(top-j+1); 
		}
	}
	cout<<ans<<endl;
	return 0;
}