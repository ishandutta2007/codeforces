#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn],sum[maxn];
vector<int>v[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		int flg=0;
		for(int i=0;i<n;i++)
			v[s[i]-96].push_back(i);
		for(int i=1;i<=26;i++)
			if(v[i].size()){
				for(int j=1;j<=n;j++)
					sum[j]=sum[j-1]+(s[j-1]==i+96);
				for(int j=1;j<=26;j++)
					if(i!=j&&v[j].size())
						for(int k=1;k<v[j].size();k++)
							flg|=(sum[v[j][k]+1]==sum[v[j][k-1]]);
				if(flg)
					break;
			}
		puts(flg? "NO":"YES");
		for(int i=1;i<=26;i++)
			v[i].clear();
	}
	return 0;
}