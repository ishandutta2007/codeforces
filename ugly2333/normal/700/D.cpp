//CF 700D
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
const int N = 100005;
const int Q = 333;
int n,a[N];
int q,l[N],r[N],ans[N];
pair<int,int> p[N];
int ff,f[N],sf[Q][N],h[N];
int cnt[N],s[N],ss[Q+Q];
void inc(int x){
	if(!h[x]){
		s[cnt[x]]--;
		s[++cnt[x]]++;
	}
}
void dec(int x){
	if(!h[x]){
		s[cnt[x]]--;
		s[--cnt[x]]++;
	}
}
priority_queue<int> PQ;
int main()
{
	int i,j,k,x,y,z,cl,cr;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	ff=0;
	for(i=1;i<N;i=i+1)
		if(cnt[i]>Q){
			f[++ff]=i;
			h[i]=1;
			for(j=1;j<=n;j=j+1){
				sf[ff][j]=sf[ff][j-1];
				if(a[j]==i)
					sf[ff][j]++;
			}
		}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",l+i,r+i);
		p[i]=make_pair(l[i]/Q*Q+r[i]/Q,i);
	}
	sort(p+1,p+q+1);
	cl=1;
	cr=0;
	memset(cnt,0,sizeof(cnt));
	for(i=1;i<=q;i=i+1){
		j=p[i].second;
		while(cl>l[j]){
			inc(a[--cl]);
		}
		while(cr<r[j]){
			inc(a[++cr]);
		}
		while(cl<l[j]){
			dec(a[cl++]);
		}
		while(cr>r[j]){
			dec(a[cr--]);
		}
		ans[j]=0;
		for(k=1;k<=Q;k=k+1)
			ss[k]=s[k];
		for(k=1;k<=ff;k=k+1){
			x=sf[k][cr]-sf[k][cl-1];
			if(x>Q)
				PQ.push(-x);
			else
				ss[x]++;
		}
		x=0;
		for(k=1;k<=Q;k=k+1){
			if(ss[k]){
				//cout<<k<<ss[k]<<endl;
				if(x){
					ss[k]--;
					ans[j]+=x+k;
					if(x+k>Q)
						PQ.push(-x-k);
					else
						ss[x+k]++;
					x=0;
				}
				if(ss[k]&1)
					x=k;
				ss[k]>>=1;
				ans[j]+=ss[k]*(k+k);
				if(k+k>Q){
					while(ss[k]){
						ss[k]--;
						PQ.push(-k-k);
					}
				}
				else
					ss[k+k]+=ss[k];
				ss[k]=0;
			}
		}
		if(x)
			PQ.push(-x);
		while(1){
			x=PQ.top();
			PQ.pop();
			if(PQ.empty())
				break;
			y=PQ.top();
			PQ.pop();
			ans[j]-=x+y;
			PQ.push(x+y);
		}
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}
/*

*/