#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
unsigned long long key=1e9+7,Key[210000],A[50],w[50];
int n,m,fir[10107],mo=10007,pd[50],next[50],sign,len;
char s[210000],t[210000];
vector<int>ans;
void insert(unsigned long long k){
//	cout<<k<<" ";
	int k1=k%mo; len++; w[len]=k; next[len]=fir[k1]; fir[k1]=len;
}
int find(unsigned long long k,unsigned long long kk){
	int k1=k%mo; 
//	cout<<k<<" "<<kk<<endl;
	for (int i=fir[k1];i;i=next[i]) if (pd[i]!=sign&&w[i]==k&&A[i-1]==kk){
		pd[i]=sign; return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1); scanf("%s",t+1);
	n=strlen(s+1); m=strlen(t+1);
	if (n<m){
		printf("0\n"); return 0;
	}
//	cout<<"insert"<<endl;
	Key[0]=1; for (int i=1;i<=n;i++) Key[i]=Key[i-1]*key;
	for (int i=0;i<26;i++){
		unsigned long long k1=0;
		for (int j=1;j<=m;j++){
			if (t[j]=='a'+i) k1+=Key[j-1];
		}
		insert(k1);
	}
	for (int i=0;i<26;i++)
		for (int j=n-m+2;j<=n;j++)
			if (s[j]=='a'+i) A[i]+=Key[j-(n-m+2)];
	for (int i=n-m+1;i;i--){
		for (int j=0;j<26;j++) A[j]=A[j]*key;
		A[s[i]-'a']++; sign++; int flag=0;
	//	for (int j=0;j<26;j++) cout<<A[j]<<" "; cout<<endl;
		sign++;
		for (int j=0;j<26;j++)
			if (find(A[j],w[j+1])==0) {flag=1; break;}
		if (flag==0) ans.push_back(i);
		int k1=s[i+m-1]-'a'; A[k1]-=Key[m-1];
	}
	cout<<ans.size()<<endl; sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); cout<<endl;
	return 0;
}