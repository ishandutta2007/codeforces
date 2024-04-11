#include<bits/stdc++.h>
const long long N=200005;
long long hi,ls,n,X[N],t,A[N],bk[N];
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(int i=0;i<n;++i)cin>>A[i];
	for(int i=0;i<n;++i)cin>>X[i],--X[i];
	for(int i=0;i<n;++i)if((X[i]<i||(i<n-1&&X[i]>X[i+1]))||(X[i]!=i&&(X[X[i]]!=X[i]||(X[i]+1<n&&A[X[i]+1]-1==A[X[i]]))))cout<<"No",std::exit(0);
	for(int i=0;i<n;++i)if(X[i]>i){
		for(int j=max(hi,1ll+i);j<X[i]+1;++j)bk[j]=1;
		hi=max(hi,X[i]);
	}
	cout<<"Yes\n";
	for(int i=0;i<n;++i)(i<n-1&&bk[i+1]?hi=A[i+1]+t:hi=A[i]+t),(i>0&&hi==ls?cout<<hi+1<<" ":cout<<hi<<" "),ls=hi;
	return 0;
}