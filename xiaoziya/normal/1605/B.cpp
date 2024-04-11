#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n;
string s;
vector<int>ans[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>n>>s,n=s.size(),s=" "+s;
		int res=0;
		while(1){
			int flg=0;
			for(int i=1;i<n;i++)
				if(s[i]>s[i+1])
					flg=1;
			if(flg==0)
				break;
			res++;
			for(int i=1,j=n;i<=n;){
				while(j>=1&&s[j]=='1')
					j--;
				while(i<=n&&s[i]=='0')
					i++;
				if(j<1||i>n||i>j)
					break;
				ans[res].push_back(i),ans[res].push_back(j),swap(s[i],s[j]);
			}
		}
		printf("%d\n",res);
		for(int i=1;i<=res;i++){
			printf("%d ",ans[i].size());
			sort(ans[i].begin(),ans[i].end());
			for(int j=0;j<ans[i].size();j++)
				printf("%d%c",ans[i][j],j+1==ans[i].size()? '\n':' ');
			ans[i].clear();
		}
	}
	return 0;
}