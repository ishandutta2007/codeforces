#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,T,ans,flg;
int a[maxn],tot[maxn],t[maxn],o[3];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),flg=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),tot[a[i]]++,flg|=(tot[a[i]]>(n+1)/2);
		if(flg){
			puts("-1");
			for(int i=1;i<=n;i++)
				tot[i]=0;
			continue;
		}
		vector< pair<int,int> >s;
		ans=0;
		for(int i=1;i<=n;i++){
			int j=i;
			while(j+1<=n&&a[j+1]!=a[j])
				j++;
			t[a[i]]++,t[a[j]]++,s.push_back(make_pair(i,j)),ans++,i=j;
		}
		int pos=0;
		for(int i=1;i<=n;i++)
			if(t[i]>ans+1)
				pos=i;
		if(pos!=0){
			o[0]=o[1]=o[2]=0;
			for(int i=0;i<s.size();i++){
				int l=s[i].first,r=s[i].second;
				for(int k=l;k<r;k++)
					o[(a[k]!=pos)+(a[k+1]!=pos)]++;
			}
			while(t[pos]>ans+1&&o[2])
				o[2]--,ans++;
		}
		printf("%d\n",ans-1);
		for(int i=1;i<=n;i++)
			tot[i]=t[i]=0;
	}
	return 0;
}