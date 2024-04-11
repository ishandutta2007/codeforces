#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int,int> pii;

const int MAXN=200005;

int n,m,d,cnt,a[MAXN],id[MAXN],bel[MAXN];
set <pii> S;
set <pii> :: iterator it;

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

inline bool cmp(const int &x,const int &y){
	return a[x]<a[y];
}

int main(){
	read(n),read(m),read(d);
	for (int i=1;i<=n;++i) read(a[i]),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1;i<=n;++i){
		it=S.lower_bound(make_pair(a[id[i]]-d,0));
		if (it!=S.begin()){
			--it;
			bel[id[i]]=it->second;
			S.erase(it);
			S.insert(make_pair(a[id[i]],bel[id[i]]));
		} else{
			bel[id[i]]=++cnt;
			S.insert(make_pair(a[id[i]],cnt));
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;++i) printf("%d ",bel[i]);
	return 0;
}