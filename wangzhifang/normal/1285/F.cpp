//https://codeforces.com/contest/1285/submission/143167759
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
constexpr int V=100000,S1=47,S2=4000,S3=5000000;
int low[V+10],pr[V/10],ptop;
int b[V+10][2];
void sieve(int x){
	int i,j;
	for(i=2;i<=x;++i){
		if(!low[i]) ++ptop,low[pr[ptop]=i]=ptop;
		for(j=1;pr[j]*i<=x;++j){
			low[pr[j]*i]=j;
			if(low[i]==j) break;
		}
	}
}
int a[100010],g[S2+10][S2+10];
int vis[V+10];
inline void up(long long &x,long long y){if(y>x) x=y;}
int gcd(int x,int y){
	
	if(x<=S2) return g[x][y%x];
	if(y<=S2) return g[y][x%y];
	if(pr[low[b[x][1]]]==b[x][1]){
		const int ans=g[b[x][0]][y%b[x][0]];
		if(y%b[x][1]==0) return ans*b[x][1];
		return ans;
	}
	else{
		const int ans=g[b[x][0]][y%b[x][0]];
		return ans*g[b[x][1]][y/ans%b[x][1]];
	}
}
int t[100010];
int ti[V+10];
vector<int>vec[V+10];
int main(){
	sieve(V);
	for(int i=1;i<=S2;++i) g[i][0]=g[0][i]=i;
	for(int i=1;i<=S2;++i){
		for(int j=1;j<=i;++j){
			g[i][j]=g[j][i]=g[j][i%j];
		}
	}
	for(int i=1;i<=V;++i){
		if(i>S2){
			int tmp=i,lst=1;
			while(tmp>1){
				lst*=pr[low[tmp]];
				if(lst==i){
					b[i][0]=lst/tmp;
					b[i][1]=tmp;
					break;
				}
				if(lst>=S1){
					b[i][0]=lst;
					b[i][1]=i/lst;
					break;
				}
				tmp/=pr[low[tmp]];
			}
		}
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;++i){
		cin>>a[i];
		vis[a[i]]=1;
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	for(int i=n; --i; )
		for(int x=a[i],j=a[i]<<1; j<=V; j+=x)
			if(vis[j]){
				vis[x]=0;
				a[i]=a[i+1];
				break;
			}
	n=unique(a+1,a+1+n)-a-1;
	long long ans=a[n];
	for(int t=3; t; --t){
		for(int i=1; i<=n; ++i)
			vis[a[i]]=i;
		for(int i=1; i<=V; ++i){
			ti[i]=bool(vis[i]);
			vec[i].clear();
			for(int j=i<<1; j<=V; j+=i)
				if(vis[j])
					++ti[i],vec[i].emplace_back(vis[j]);
		}
		for(int i=V; i; --i){
			int pos=0,v=0;
			for(const int&j:vec[i]){
				const int x=a[j]/i;
				int tmp=x;
				bool flg=1;
				while(tmp>1){
					if(ti[pr[low[tmp]]]>1){
						flg=0;
						break;
					}
					tmp/=pr[low[tmp]];
				}
				if(flg){
					up(ans,(long long)(i)*x*v);
					if(x>v){
						if(pos){
							vis[a[pos]]=0;
							a[pos]=1;
						}
						v=x,pos=j;
					}
					else{
						vis[a[j]]=0;
						a[j]=1;
					}
				}
			}
			for(const int&j:vec[i]){
				const int x=a[j]/i;
				if(x!=v)
					up(ans,(long long)(i)*x*v);
				if(x<v){
					vis[a[j]]=0;
					a[j]=1;
				}
			}
		}
		for(int i=n; --i; )
			if(a[i]==1)
				a[i]=a[i+1];
		n=unique(a+1,a+1+n)-a-1;
	}
	int now=t[n]=a[n];
	for(int i=n; --i; t[i]=now=gcd(now,a[i]));
	int l=1;
	forward_list<pair<int,int> >lst;
	for(int i=1; i<=n; ++i)
		lst.push_front(pair<int,int>(a[i],t[i]));
	for(int i=n; i>l; --i){
		while(l<i&&(long long)(a[i])*a[l]<=ans*t[l])
			++l;
		if(l>=i)
			break;
		if(lst.front().first==a[i])
			lst.pop_front();
		for(auto bit=lst.before_begin(),it=lst.begin(); it!=lst.end(); ){
			if(it->first<a[l]){
				while((++it)!=lst.end())
					lst.erase_after(bit);
				lst.erase_after(bit);
				break;
			}
			if(it->first*(long long)(a[i])<=ans*it->second){
				++it;
				lst.erase_after(bit);
				continue;
			}
			up(ans,(long long)a[i]*it->first/gcd(a[i]-it->first,it->first));
			++bit,++it;
		}
	}
	cout<<ans<<'\n';
	return 0;
}