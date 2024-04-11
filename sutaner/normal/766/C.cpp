#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 1005
#define M (int)(1e9+7)
#define INF (int)2e9
using namespace std;
int dp1[maxn];
int dp2[maxn][maxn];
int dp3[maxn][maxn];
int pro[maxn];
int num[26];
char s[maxn];int len;
int DP1(int pos){
	if(pos>=len)return 1;
	if(dp1[pos])return dp1[pos];
	int& ans=dp1[pos];
	ans=0;
	for(int i=pos+1;i<=pro[pos]+1;i++){
		ans=(DP1(i)+ans)%M;
	}
	return ans;
}
/*int DP2(int pos){
	if(dp2[l][r])return dp2[l][r];
	int& ans=dp2[l][r];
	if(pro[l]>=r)return ans=1;
	ans=INF;
	for(int i=l;i<r;i++){
		ans=min(DP2(l,i)+DP2(i+1,r),ans);
	}
	return ans;
}
int DP3(int l,int r){
	if(dp3[l][r])return dp3[l][r];
	int& ans=dp3[l][r];
	if(pro[l]>=r)return r-l+1;
	ans=0;
	for(int i=l;i<=pro[l];i++){
		ans=max(max(DP3(l,i),DP3(i+1,r)),ans);
	}
	return ans;
}*/
void init(){
	int ch[26],minnum=INF;
	memset(ch,0,sizeof(ch));
	for(int i=0;i<len;i++){
		int k=-1;
		for(int j=i;j<len;j++){
			minnum=min(minnum,num[s[j]-'a']);
			if(j-i+1>minnum){
				k=j-1;
				break;
			}
		}
		pro[i]=(k==-1)?len-1:k;
		memset(ch,0,sizeof(ch));
		minnum=INF;
	}
	return;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&len);
	scanf("%s",s);
	for(int i=0;i<26;i++)
		scanf("%d",&num[i]);
	init();
	int max1=0;
	for(int i=0;i<len;i++){
		max1=max(max1,pro[i]-i+1);
	}
	int min1=0;
	for(int i=0;i<len;i++){
		i=pro[i];
		min1++;
	}
	printf("%d\n%d\n%d",DP1(0),max1,min1);
	return 0;
}