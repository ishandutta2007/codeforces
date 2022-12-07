#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int H;
map<int,vector<int>> mp;
vector<int> query(int x){
	if (mp.count(x)) return mp[x];
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int y;
	scanf("%d",&y);
	if (y==0) exit(0);
	vector<int> res;
	For(i,1,y){
		int z;
		scanf("%d",&z);
		res.PB(z);
	}
	if (res.size()==2) throw x;
	random_shuffle(res.begin(),res.end());
	return mp[x]=res;
}
void find_fa(int &x,int &fa,int &d){
	static int q[555];
	memset(q,0,sizeof(q));
	int h=20,t=21;
	q[20]=x,q[21]=fa;
	vector<int> tmp;
	for (;;h--){
		tmp=query(q[h]);
		if (tmp.size()==1) break;
		q[h-1]=tmp[tmp[0]==q[h+1]];
	}
	for (;;t++){
		tmp=query(q[t]);
		if (tmp.size()==1) break;
		q[t+1]=tmp[tmp[0]==q[t-1]];
	}
	int p=(h+t)/2,pos=0;
	x=q[p]; d=H-(t-h)/2; tmp=query(x);
	for (;tmp[pos]==q[p-1]||tmp[pos]==q[p+1];++pos);
	fa=tmp[pos];
}
void solve(){
	mp.clear();
	try{
		scanf("%d",&H);
		if (H==0) exit(0);
		int x=rand()%((1<<H)-1)+1,fa=-1,d=0;
		vector<int> tmp=query(x);
		if (tmp.size()==1) fa=tmp[0],d=H;
		else fa=tmp[0],find_fa(x,fa,d);
		if (d==2) throw fa;
		for (;d>4;d--){
			tmp=query(fa);
			int adj=tmp[tmp[0]==x],p=adj,pa=fa;
			For(j,d,H-1){
				vector<int> ttmp=query(p);
				int tmpval=pa; pa=p;
				p=(ttmp[ttmp[0]==tmpval]);
			}
			if (query(p).size()==1){
				int pos=0;
				tmp=query(fa);
				for (;tmp[pos]==x||tmp[pos]==adj;++pos);
				x=fa; fa=tmp[pos];
			}
			else x=fa,fa=adj;
		}
		tmp=query(fa);
		int p1=(tmp[0]==x),p2=p1+1+(tmp[p1+1]==x);
		query(p1=tmp[p1]); query(p2=tmp[p2]);
		static int q[10]; *q=0;
		tmp=query(p1);
		for (auto i:tmp) if (i!=fa) q[++*q]=i;
		tmp=query(p2);
		for (auto i:tmp) if (i!=fa) q[++*q]=i;
		For(i,1,(*q)-1) query(q[i]);
		throw q[*q];
	}
	catch(int ans){
		cout<<"! "<<ans<<endl;
		return;
	}
}
int main(){
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
6
3 61 52 3
3 27 1 59
3 31 55 52
3 27 58 46
1 31
3 53 8 1
1 61
3 18 39 52
3 59 13 14
3 18 32 24
3 62 9 13
1 32
*/