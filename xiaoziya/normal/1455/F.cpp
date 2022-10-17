#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,k,T;
string s;
string f[maxn][2];
inline char get(char c){
	return (c=='a'||c==k+96)? 'a':(c-1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k),cin>>s;
		f[1][0].resize(2),f[1][1].resize(2);
		f[1][0][0]=get(s[0]),f[1][0][1]=s[1],f[1][1][0]=s[1],f[1][1][1]=s[0];
//		cout<<"i="<<1<<"\n"<<f[1][0]<<"\n"<<f[1][1]<<"\n";
		for(int i=2;i<=n;i++){
			string lst1=f[i-1][0],lst2=f[i-1][1];
			string nxt1=lst1,nxt2=lst1,nxt3=lst2,nxt4=lst2;
			swap(nxt1[i-1],nxt1[i-2]),nxt2[i-1]=get(nxt2[i-1]),nxt3[i-2]=get(nxt3[i-2]);
			if(i>2)
				swap(nxt4[i-2],nxt4[i-3]);
			string mn1=nxt1<nxt2? nxt1:nxt2,mn2=nxt3<nxt4? nxt3:nxt4;
			f[i][0]=(mn1<mn2? mn1:mn2)+s[i];
			nxt1=lst1,nxt1[i-1]=s[i],f[i][1]=nxt1+s[i-1];
//			cout<<"i="<<i<<"\n"<<f[i][0]<<"\n"<<f[i][1]<<"\n";
		}
		f[n][0].resize(n);
		cout<<f[n][0]<<"\n";
	}	
	return 0;
}