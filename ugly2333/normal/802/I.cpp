// CF 802I
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
char s[111111];
pair<pair<int,int>,int> a[111111];
int sa[111111],rk[111111],lcp[111111],p[111111],sz[111111];
vector<int> v[111111];
LL ans[111111];
int main()
{
	int T,n,i,x,h,j,y,xx,yy;
	LL ss;
	cin>>T;
	while(T--){
		scanf("%s",&s);
		n=strlen(s);
		for(i=n-1;i>=0;i=i-1)
			s[i+1]=s[i];
		s[0]=0;
		for(i=1;i<=n;i=i+1){
			rk[i]=s[i]-'a'+1;
		}
		for(x=1;x<=n;x=x*2){
			for(i=1;i<=n;i=i+1){
				a[i].second=i;
				a[i].first.first=rk[i];
				if(i+x<=n)
					a[i].first.second=rk[i+x];
				else
					a[i].first.second=0;
			}
			sort(a+1,a+n+1);
			rk[0]=0;
			for(i=1;i<=n;i=i+1){
				if(a[i].first==a[i-1].first)
					rk[a[i].second]=rk[a[i-1].second];
				else
					rk[a[i].second]=rk[a[i-1].second]+1;
				//cout<<rk[i]<<' ';
			}
			//cout<<endl;
		}
		for(i=1;i<=n;i=i+1){
			sa[rk[i]]=i;
			//cout<<rk[i]<<endl;
		}
		memset(lcp,0,sizeof(lcp));
		memset(ans,0,sizeof(ans));
		memset(sz,0,sizeof(sz));
		h=0;
		for(i=1;i<=n;i=i+1){
			j=sa[rk[i]-1];
			if(h>0)
				h--;
			while(i+h<=n&&j+h<=n&&s[i+h]==s[j+h]){
				h++;
			}
			lcp[rk[i]-1]=h;
		}
		for(i=1;i<n;i=i+1)
			v[lcp[i]].push_back(i);
		ss=0;
		for(i=n;i>=1;i=i-1)
		{
			ans[i]=ans[i+1];
			x=rk[n+1-i];
			sz[x]=1;
			ans[i]++;
			for(j=0;j<v[i].size();j=j+1){
				y=v[i][j];
				xx=sz[y];
				yy=sz[y+1];
				ans[i]+=(LL)2*xx*yy;
				sz[y-xx+1]=xx+yy;
				sz[y+yy]=xx+yy;
				sz[y]=xx+yy;
				sz[y+1]=xx+yy;
				//cout<<xx<<' '<<yy<<endl;
			}
			ss+=ans[i];
			//cout<<ans[i]<<' ';
		}
		cout<<ss<<endl;
		for(i=0;i<=n+1;i=i+1)
			v[i].clear();
	}
	return 0;
}
// 1 abbbaaaaa