//CF 860B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 70077;
int a[N][11];
int ans[N],ansx[N];
pair<int,int> b[N*60];
int main()
{
	char ch[11];
	int n,i,j,k,x,p,h;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=9;j=j+1)
			a[i][j]=ch[j]-'0';
	}
	memset(ansx,0,sizeof(ansx));
	p=1;
	/*for(k=1;k<=5;k=k+1){
		p*=10;
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i=i+1){
			x=0;
			for(j=1;j<=9;j=j+1){
				x=x*10+a[i][j];
				x%=p;
				if(j>=k)
					v[x].push_back(i);
			}
		}
		for(i=0;i<=p;i=i+1){
			if(!v[i].size())
				continue;
			x=unique(v[i].begin(),v[i].end())-v[i].begin();
			if(x==1&&!ansx[v[i][0]]){
				ans[v[i][0]]=i;
				ansx[v[i][0]]=k;
			}
		}
	}*/
	for(k=1;k<=9;k=k+1){
		p*=10;
		h=0;
		for(i=1;i<=n;i=i+1){
			x=0;
			for(j=1;j<=9;j=j+1){
				x=x*10+a[i][j];
				x%=p;
				if(j>=k)
					b[++h]=make_pair(x,i);
			}
		}
		b[0].first=-2;
		b[h+1].first=b[h].first+1;
		sort(b+1,b+h+1);
		h=unique(b+1,b+h+1)-b-1;
		for(i=1;i<=h;i=i+1){
			//cout<<b[i].first<<' '<<b[i].second<<endl;
			if(b[i].first==b[i-1].first)
				continue;
			if(b[i].first==b[i+1].first&&b[i].second!=b[i+1].second)
				continue;
			if(!ansx[b[i].second]){
				//cout<<"POPOPO";
				ans[b[i].second]=b[i].first;
				ansx[b[i].second]=k;
			}
		}
	}
	for(i=1;i<=n;i=i+1){
		//cout<<ansx[i]<<' '<<ans[i]<<endl;
		for(j=ansx[i]-1;j>=0;j=j-1){
			ch[j]='0'+ans[i]%10;
			ans[i]/=10;
		}
		for(j=0;j<ansx[i];j=j+1)
			cout<<ch[j];
		cout<<endl;
	}
	return 0;
}