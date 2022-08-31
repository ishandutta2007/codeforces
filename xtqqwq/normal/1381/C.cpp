#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,x,y;
int cnt[100005],ans[100005],a[100005];
vector<int> v[100005];
set<pii> s;

int main(){
	int T=readint();
	while(T--){
		n=readint(); x=readint(); y=readint();
		for(int i=1;i<=n+1;i++) v[i].clear(),cnt[i]=0;
		for(int i=1;i<=n;i++) a[i]=readint(),v[a[i]].pb(i),cnt[a[i]]++,ans[i]=0;
		s.clear();
		for(int i=1;i<=n+1;i++) if(cnt[i]) s.insert(mp(cnt[i],i));
		int knd;
		for(int i=1;i<=n+1;i++) if(!cnt[i]) knd=i;
		for(int i=1;i<=x;i++){
			pii t=*(--s.end());
			s.erase(--s.end());
			ans[v[t.se].back()]=t.se;
			v[t.se].pop_back();
			t.fi--;
			if(t.fi) s.insert(t);
		}
		y-=x;
		bool fl=0;
		while(y>1){
			pii t1=*(--s.end()),t2=*s.begin();
			if(t1==t2){
				fl=1;
				break;
			}
			s.erase(s.find(t1)),s.erase(s.find(t2));
			ans[v[t1.se].back()]=t2.se;
			ans[v[t2.se].back()]=t1.se;
			v[t1.se].pop_back(),v[t2.se].pop_back();
			t1.fi--,t2.fi--;
			if(t1.fi) s.insert(t1);
			if(t2.fi) s.insert(t2);
			y-=2;
		}
		if(fl){
			printf("NO\n");
			continue;
		}
		if(y==1){
			pii t1=*(--s.end()),t2=*s.begin();
			if(t1!=t2) ans[v[t1.se].back()]=t2.se;
			else{
				for(int i=1;i<=n;i++){
					if(ans[i]&&ans[i]!=t1.se&&a[i]!=t1.se&&a[i]!=ans[i]){
						ans[v[t1.se].back()]=t1.se;
						swap(ans[v[t1.se].back()],ans[i]);
						fl=1;
						break;
					}
				}
				if(!fl){
					printf("NO\n");
					continue;
				}
			}
		}
		for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=knd;
		printf("YES\n");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}