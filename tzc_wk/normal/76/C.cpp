#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
ll n,m,t,a[25][25],b[25],c[1<<22];char s[200005];
ll sum[1<<22];
inline void go(int x1,int y1,int x2,int v){
//	printf("%d %d %d %d\n",x1,y1,x2,v);
//	for(int i=0;i<(1<<m);i++){
//		if((x1&i)==i&&(y1&i)!=i&&(x2&i)!=i) printf("%d %d\n",i,v),sum[i]+=v;
//	}
	sum[x1]+=v;sum[y1]-=v;sum[x2]-=v;sum[y1&x2]+=v;
}
bool used[25];
int to=0;
set<int> st[25];
int main(){
	scanf("%d%d%d%s",&n,&m,&t,s+1);
	for(int i=1;i<=n;i++) used[s[i]-'A']=1;
	for(int i=0;i<m;i++) scanf("%lld",&b[i]);
	for(int i=0;i<m;i++) if(used[i]) to|=(1<<i);
	for(int i=1;i<(1<<m);i++) c[i]=b[(int)(log2(i&(-i)))]+c[i^(i&(-i))];
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++) st[s[i]-'A'].insert(i);
	for(int i=1;i<=n;i++){
		st[s[i]-'A'].erase(st[s[i]-'A'].find(i));
		vector<pii> v;
		for(int j=0;j<m;j++){
			if(!st[j].empty()){
				v.pb(make_pair(*st[j].begin(),j));
			}
		}
		sort(all(v));int msk=(1<<m)-1;
		for(int j=0;j<v.size();j++){
			msk^=1<<v[j].se;
			go(msk|(1<<v[j].se),(msk|(1<<v[j].se))^(1<<(s[i]-'A')),msk,a[s[i]-'A'][v[j].se]);
			if(v[j].se==s[i]-'A') break;
		}
	}
	for(int i=0;i<m;i++) for(int j=(1<<m)-1;~j;j--){
		if(!(j>>i&1)) sum[j]+=sum[j|(1<<i)];
	}
//	for(int i=0;i<(1<<m);i++) cout<<sum[i]<<endl;
	int ans=0;
	for(int i=0;i<(1<<m);i++) if(sum[((1<<m)-1)^i]+c[i]<=t&&(to|i)==to&&(to&i)!=to) ans++;
	printf("%d\n",ans);
	return 0;
}
/*
5 3 13
BACAC
4 1 2
1 2 3
2 3 4
3 4 10
*/