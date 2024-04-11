#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
string A[40],B[40];
map<string,int>M;
int n,K;
queue<string>Q;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=K;i++) cin>>A[i]>>B[i];
	string fir="a";
	M[fir]=1; Q.push(fir);
	int ans=0;
	while (!Q.empty()){
		string k=Q.front(); Q.pop();
		if (k.length()==n){
			ans++; continue;
		}
		for (int i=1;i<=K;i++)
			if (k[0]==B[i][0]){
				string k1=k; k1[0]=A[i][1];
				k1=A[i][0]+k1;
				if (M[k1]==0){
					M[k1]=1; Q.push(k1);
				}
			}
	}
	cout<<ans<<endl; return 0;
}