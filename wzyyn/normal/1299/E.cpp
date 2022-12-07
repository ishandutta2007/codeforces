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
const int N=805;
const int type=0;
int n,p[N],times;
int m3[N],m5[N],m7[N];
int m2[N],m4[N],m8[N];
int ans[N],pos[N];
void init(){
	srand(time(NULL));
	For(i,1,n) p[i]=i;
	random_shuffle(p+1,p+n+1);
	if (p[1]>n/2) For(i,1,n) p[i]=n-p[i]+1;
}
int query(vector<int> a){
	++times;
	if (type==0){
		printf("? %d ",a.size());
		for (auto i:a) printf("%d ",i);
		puts("");
		fflush(stdout);
		int ans;
		scanf("%d",&ans);
		return ans;
	}
	else{
		int sum=0;
		for (auto i:a) sum+=p[i];
		return sum%a.size()==0;
	}
}
void find1n(){
	int cnt=0;
	For(i,1,n){
		vector<int> tmp;
		For(j,1,n) if (j!=i) tmp.PB(j);
		if (query(tmp)){
			if (!cnt) ans[i]=1,pos[1]=i;
			else ans[i]=n,pos[n]=i;
			if (++cnt==2) break;
		}
	}
}
void findodd(){
	For(i,1,n) if (!ans[i]){
		vector<int> tmp;
		tmp.PB(i); tmp.PB(pos[1]);
		m2[i]=query(tmp);
	}
}
void findbf(int times){
	For(R,1,times){
		int cnt=0;
		static int q[N]; q[0]=0;
		For(i,1,n) if (!ans[i]) q[++*q]=i;
		For(i,1,*q){
			vector<int> tmp;
			For(j,1,*q) if (j!=i) tmp.PB(q[j]);
			if (query(tmp)){
				int x=q[i];
				ans[x]=R+1;
				if ((ans[x]+m2[x])&1)
					ans[x]=n-ans[x]+1;
				pos[ans[x]]=x;
			}
		}
	}
}
vector<int> op[10];
void solve(int *m,int v){
	int p=-1;
	For(i,0,v-1)
		if (!op[i].size())
			p=i;
	assert(p!=-1);
	For(i,1,n) if (!ans[i]){
		m[i]=-1;
		For(j,0,v-1) if (op[j].size()){
			vector<int> tmp=op[j];
			tmp.PB(i);
			if (query(tmp)){
				m[i]=j;
				break;
			}
		}
		if (m[i]==-1) m[i]=p;
	}
}
void find3(){
	op[0].PB(pos[1]); op[0].PB(pos[2]);
	op[1].PB(pos[1]); op[1].PB(pos[4]);
	op[2].resize(0);
	solve(m3,3);
}
void find5(){
	int v=(1+2+3+(n-3))%5;
	For(i,0,4) op[i].resize(0);
	For(i,0,3){
		int vv=(10-(v+3-i))%5;
		For(j,1,3) op[vv].PB(pos[j]);
		op[vv].PB(pos[n-i]);
	}
	solve(m5,5);
}
void find7(){
	For(i,0,6) op[i].resize(0);
	For(i,1,4){
		int v=(7-(1+2+3+4-i+(n-3)+(n-2)+(n-1))%7)%7;
		For(j,1,4) if (j!=i) op[v].PB(pos[j]);
		For(j,1,3) op[v].PB(pos[n-j]);
	}
	For(i,1,2){
		int v=(7-(2+3+4+n+n+n-3-2-1+i)%7)%7;
		For(j,2,4) op[v].PB(pos[j]);
		For(j,0,3) if (j!=i) op[v].PB(pos[n-j]);
	}
	solve(m7,7);
}
void find4(){
	For(i,1,n) if (!ans[i]){
		vector<int> tmp;
		tmp.PB(pos[1]); tmp.PB(pos[2]);
		tmp.PB(pos[m2[i]+3]);
		tmp.PB(i);
		m4[i]=(m2[i]+(query(tmp)^m2[i]?2:0));
	}
}
void find8(){
	For(i,1,n) if (!ans[i]){
		vector<int> tmp;
		For(j,1,4) if (j%4!=m4[i]) tmp.PB(pos[j]);
		For(j,0,3) tmp.PB(pos[n-j]);
		tmp.PB(i);
		m8[i]=(m4[i]+(query(tmp)^(m4[i]==0)?4:0));
	}
}
void output(){
	if (ans[1]>n/2)
		For(i,1,n) ans[i]=n+1-ans[i];
	if (type==0){
		printf("!");
		For(i,1,n) printf(" %d",ans[i]);
		fflush(stdout);
	}
	else{
		cout<<times<<' '<<18*n<<endl;
		For(i,1,n)
			if (ans[i]!=p[i])
				printf("GG %d %d %d\n",i,ans[i],p[i]);
	}
}
int main(){
	scanf("%d",&n);
	if (type==1) init();
	if (n==2){
		printf("! 1 2\n");
		fflush(stdout);
		return 0;
	}
	//cout<<233<<endl;
	find1n();
	//cout<<233<<endl;
	findodd();
	//cout<<233<<endl;
	if (n<=40) findbf(n/2-1); 
	else{
		findbf(3);
		find3(); find5(); find7();
		find4(); find8();
		For(i,1,n) For(j,1,n)
			if (j%3==m3[i]&&j%5==m5[i]&&j%7==m7[i]&&j%8==m8[i])
				ans[i]=j;
	}
	//cout<<233<<endl;
	output();
}