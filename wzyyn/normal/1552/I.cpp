#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=105;
int bic[1<<16|5];
void init(){
	for (int i=0;i<1<<16;i++)
		bic[i]=bic[i>>1]+(i&1); 
}
struct Bitset{
	unsigned long long a[2];
	Bitset(){
		a[0]=a[1]=0;
	}
	void clear(){
		a[0]=a[1]=0;
	}
	void set(int x){
		a[x>>6]|=(1ull<<(x&63));
	}
	bool get(int x)const{
		return (a[x>>6]>>(x&63))&1;
	}
	
	// 
	#define OP(op)\
		Bitset operator op(const Bitset &b)const{\
			Bitset c;\
			c.a[0]=a[0] op b.a[0];\
			c.a[1]=a[1] op b.a[1];\
			return c;\
		}
	OP(|)
	OP(^)
	OP(&)
	#undef OP(op)
	int count()const{
		int ans=0;
		ans+=bic[a[0]&65535]+bic[(a[0]>>16)&65535]+bic[(a[0]>>32)&65535]+bic[a[0]>>48];
		ans+=bic[a[1]&65535]+bic[(a[1]>>16)&65535]+bic[(a[1]>>32)&65535]+bic[a[1]>>48];
		return ans;
	}
	bool operator ==(const Bitset &b)const{
		return a[0]==b.a[0]&&a[1]==b.a[1];
	}
	bool operator !=(const Bitset &b)const{
		return a[0]!=b.a[0]||a[1]!=b.a[1];
	}
	operator bool(){
		return a[0]!=0||a[1]!=0;
	}
}B[N],C[N];
int n,m,bad,ct;
int vis[N],e[N][N];

bool Judpre(int *mode){
	int s=0;
	for (int i=1;i<=ct;i++)
		if (mode[i]==1) ++s;
	if (s>1) return 0;
	for (int i=1;i<ct;i++)
		if (mode[i]<mode[i+1])
			return 0;
	return 1;
}
bool Judsuf(int *mode){
	int s=0;
	for (int i=1;i<=ct;i++)
		if (mode[i]==1) ++s;
	if (s>1) return 0;
	for (int i=1;i<ct;i++)
		if (mode[i]>mode[i+1])
			return 0;
	return 1;
}
bool Judinter(int *mode){
	int s1=0;
	for (int i=1;i<=ct;i++)
		if (mode[i]==1) ++s1;
	if (s1>2) return 0;
	int l=1,r=ct;
	for (;l!=ct&&mode[l]<=mode[l+1];++l);
	for (;r!=1&& mode[r]<=mode[r-1];--r);
	if (s1==2&&mode[l]==2){
		for (int i=1;i<=l;i++)
			if (mode[i]==1) --s1;
		if (s1!=1) return 0;
	}
	return l>=r;
}
void Insert(int loc,Bitset A){
	++ct;
	for (int i=ct;i>loc;i--)
		C[i]=C[i-1];
	C[loc]=A;
}
void Insert(Bitset A){
	/*printf("insv %d\n",ct);
	for (int i=1;i<=ct;i++,puts(""))
		for (int j=1;j<=n;j++)
			putchar(C[i].get(j)?'1':'0');
	for (int i=1;i<=n;i++)
		putchar(A.get(i)?'1':'0');
	puts("");*/
	Bitset Copy_A=A;
	static int mode[N];
	for (int i=1;i<=ct;i++){
		Bitset Int=A&C[i];
		if (Int) mode[i]=(Int!=C[i]?1:2);
		else mode[i]=0;
		A=A^Int;
	}
	bool pre=0,suf=0,inter=0;
	pre=Judpre(mode);
	suf=Judsuf(mode);
	inter=Judinter(mode);
	//printf("%d %d %d %d\n",ct,pre?1:0,suf?1:0,inter?1:0);
	
	if (!inter) return bad=1,void(0);
	if (!pre&&!suf&&A) return bad=1,void(0);
	if (!suf&&A){
		reverse(C+1,C+ct+1);
		reverse(mode+1,mode+ct+1);
	}
	if (A){
		C[++ct]=A;
		mode[ct]=2;
	}
	
	for (int i=ct;i>=1;i--)
		if (mode[i]==1){
			Bitset b1=C[i]&Copy_A;
			Bitset b2=b1^C[i];
			if (i>=2&&mode[i-1]!=0)
				C[i]=b1,Insert(i+1,b2);
			else if (i!=ct&&mode[i+1]!=0)
				C[i]=b2,Insert(i+1,b1);
			else assert(0);
		}
}

struct Mynode{
	Bitset fi;
	vector<Bitset> se;
	bool operator <(const Mynode &a)const{
		if (fi.count()!=a.fi.count())
			return fi.count()>a.fi.count();
		return se.size()<a.se.size();
	}
}node[N];
int nodet;
void update(int S){
	static int q[N];
	int h=0,t=1; ct=1;
	q[1]=S; vis[S]=1; C[1]=B[S];
	while (h!=t&&!bad){
		int x=q[++h];
		for (int i=1;i<=m;i++)
			if (e[x][i]&&!vis[i]&&!bad)
				q[++t]=i,vis[i]=1,Insert(B[i]);
	}
	if (bad){
		puts("0");
		exit(0);
	}
	//printf("INFO %d\n",S);
	/*for (int i=1;i<=ct;i++){
		for (int j=1;j<=n;j++)
			putchar(C[i].get(j)?'1':'0');
		puts("");
	}*/
	++nodet;
	for (int i=1;i<=ct;i++){
		node[nodet].fi=node[nodet].fi|C[i];
		node[nodet].se.push_back(C[i]);
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d",&x);
		for (;x;--x){
			scanf("%d",&y);
			B[i].set(y);
		}
		bool flag=0;
		for (int j=1;j<i;j++)
			if (B[i]==B[j]) flag=1;
		if (flag){
			B[i].clear();
			--i,--m;
		}
	}
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (B[i]&B[j])
				if ((B[i]&B[j])!=B[i])
					if ((B[i]&B[j])!=B[j])
						e[i][j]=e[j][i]=1;
	for (int i=1;i<=m;i++)
		if (!vis[i]) update(i);
	++nodet;
	Bitset ful;
	for (int i=1;i<=n;i++) ful.set(i);
	node[nodet].fi=ful;
	node[nodet].se.push_back(ful);
	sort(node+1,node+nodet+1);
	int ans=1;
	int mo=998244353;
	for (int i=1;i<=nodet;i++){
		if (node[i].se.size()>=2)
			ans=2ll*ans%mo;
		for (auto j:node[i].se){
			int cnt=j.count();
			Bitset Copy_j=j;
			for (int k=i+1;k<=nodet;k++)
				if ((node[k].fi&Copy_j)==node[k].fi){
					Copy_j=Copy_j^node[k].fi;
					cnt-=node[k].fi.count()-1;
				}
			//cout<<cnt<<endl;
			for (;cnt;--cnt)
				ans=1ll*cnt*ans%mo;
		}
	}
	printf("%d\n",ans);
}