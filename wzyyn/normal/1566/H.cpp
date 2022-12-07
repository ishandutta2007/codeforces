#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=1000005;
int n,c,f[N];
int q[N],val[N],qval[N];
vector<int> v[N];
void init(int n){
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=2;i*i<=n;i++)
		for (int j=i*i;j<=n;j+=i*i)
			for (;f[j]%(i*i)==0;f[j]/=i);
}
vector<int> ans;
vector<bitset<40000>> flist;
vector<vector<bitset<260>>> vlist;
vector<int> idlist;
vector<vector<int>> cntlist; 
void Gauss(int x){
	static int bas[22],uni;
	static bitset<260> vec[22],univ,vis;
	for (int i=0;i<=21;i++)
		bas[i]=0,vec[i].reset();
	univ.reset();
	vis.reset();
	uni=0;
	for (int i=0;i<v[x].size();i++){
		int key=v[x][i],flg=0;
		bitset<260> tmp;
		tmp.reset(); tmp[i]=1;
		for (int j=20;j>=0;j--)
			if (key&(1<<j)){
				if (!bas[j]){
					bas[j]=key;
					vec[j]=tmp;
					flg=1;
					break;
				}
				else{
					key^=bas[j];
					tmp^=vec[j];
				}
			}
		//cout<<key<<' '<<flg<<' '<<val[x]<<' '<<x<<endl;
		if (!flg) univ[i]=1,++uni;
	}
	vector<bitset<260>> op;
	vector<int> opcnt;
	for (int T=1;T<=(uni?100:1);T++){
		bitset<260> re;
		re.reset();
		int aim=val[x];
		for (int j=0;j<v[x].size();j++)
			if (univ[j]&&(rand()&1)){
				aim^=v[x][j];
				re[j]=1;
			}
		for (int j=20;j>=0;j--)
			if (aim&(1<<j)){
				assert(bas[j]);
				aim^=bas[j];
				re^=vec[j];
			}
		int count=0;
		for (int j=0;j<v[x].size();j++)
			if (re[j]) ++count;
		if (!vis[count]){
			vis[count]=1;
			op.push_back(re);
			opcnt.push_back(count);
		}
	}
	if (op.size()==1){
		for (int j=0;j<v[x].size();j++)
			if (op[0][j]) ans.push_back(v[x][j]);
		n-=opcnt[0];
	}
	else{
		vlist.push_back(op);
		idlist.push_back(x);
		cntlist.push_back(opcnt);
		int mn=*min_element(opcnt.begin(),opcnt.end());
		n-=mn;
		int m=flist.size();
		flist.push_back(flist.back());
		for (auto i:opcnt) flist[m]|=flist[m-1]<<(i-mn);
	}
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&c,&n);
	init(c);
	for (int i=1;i<=c;i++){
		//cout<<f[i]<<endl;
		v[f[i]].push_back(i);
		if (f[i]==i) q[++*q]=i;
	}
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++) printf("%d ",q[i]);
	puts("");
	fflush(stdout);
	for (int i=1;i<=*q;i++)
		scanf("%d",&qval[q[i]]);
	int tot_xor=qval[1];
	for (int i=1;i<=c;i++)
		if (f[i]==i)
			for (int j=i;j<=c;j+=i)
				if (f[j]==j)
					val[j]^=qval[i]^tot_xor;
	val[1]=tot_xor;
	for (int i=c;i>=1;i--)
		if (f[i]==i)
			for (int j=2*i;j<=c;j+=i)
				val[i]^=val[j];
	
	bitset<40000> tmp;
	tmp[0]=1;
	flist.push_back(tmp);
	vlist.resize(1);
	idlist.resize(1);
	cntlist.resize(1);
	for (int i=1;i<=c;i++)
		if (f[i]==i) Gauss(i);
	assert(n<40000&&n>=0);
	assert(flist.back()[n]);
	for (int i=flist.size()-1;i>0;i--){
		int mn=*min_element(cntlist[i].begin(),cntlist[i].end());
		for (int j=0;j<cntlist[i].size();j++){
			int dif=cntlist[i][j]-mn;
			if (dif<=n&&flist[i-1][n-dif]){
				n-=dif;
				int idx=idlist[i];
				for (int k=0;k<v[idx].size();k++)
					if (vlist[i][j][k]) ans.push_back(v[idx][k]);
				break;
			}
		}
	} 
	sort(ans.begin(),ans.end());
	for (auto i:ans)
		printf("%d ",i);
}
/*
10 6
4 4 2 11 4 4 1
*/