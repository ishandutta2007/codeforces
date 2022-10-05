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
int n,opt[200005],ans[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++){
		char ss[3];cin>>ss+1;
		if(ss[1]=='+') opt[i]=-1;
		else scanf("%d",&opt[i]);
	}
	int sum=0;
	for(int i=1;i<=n*2;i++){
		if(opt[i]==-1) sum++;
		else sum--;
		if(sum<0) return puts("NO"),0;
	}
	for(int i=2;i<=n*2;i++){
		if(opt[i]!=-1&&opt[i-1]!=-1&&opt[i-1]>opt[i])
			return puts("NO"),0;
	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	set<int> st;
	for(int i=1;i<=n*2;i++){
		if(opt[i]==-1) st.insert(i);
		else q.push(make_pair(opt[i],i));
	}
	for(int i=1;i<=n;i++){
		pii x=q.top();q.pop();
		int y=*--st.lower_bound(x.se);
		ans[y]=i;
		st.erase(st.find(y));
	}
	bool flg=1;
	for(int i=1;i<=2*n;i++){
		if(opt[i]==-1) st.insert(ans[i]);
		else{
			int v=*st.begin();
			st.erase(st.find(v));
			if(v!=opt[i]) return puts("NO"),0;
		}
	}
	puts("YES");
	for(int i=1;i<=2*n;i++) if(ans[i]) printf("%d ",ans[i]);
	return 0;
}
/*
3
+
+
- 3
+
- 1
- 2 
*/