#include"bits/stdc++.h"
using namespace std;
#define fge getchar()
template <class MyInt>
inline void read(MyInt&x){
	x=0;int f=1;char ch=fge;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=fge;}
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=fge;
	x=x*f;
}

const int N=300005;

int f[N];
map<int,int>s;
vector<int>pl[N];
map<int,int>::iterator k,p;
int n,q,cnt;

int main(){
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	read(n),read(q);int i,op,x,j;
	for(i=1;i<=q;i++){
		read(op),read(x);
		if(op==1){
			s.insert(make_pair(++cnt,x));
			pl[x].push_back(cnt);
		}else if(op==2){
			int siz=pl[x].size();
			for(j=f[x];j<siz;j++)
				s.erase(s.find(pl[x][j]));
			f[x]=siz;
		}else{
			for(k=s.begin();k!=s.end()&&k->first<=x;)
				f[k->second]++,p=++k,s.erase(--k),k=p;
		}
		printf("%d\n",s.size());
	}
	return 0;
}