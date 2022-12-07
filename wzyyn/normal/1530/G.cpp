#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=2005;
int n,k;
char s1[N],s2[N];
int q1[N],q2[N];

pair<int,int> Do(int *q,int l,int dl,int dr){
	int p1=0,p2=0,r=l+k;
	assert(dl<=q[l]);
	assert(dr<=q[r]);
	for (int i=0;i<=l;i++) p1+=q[i]+1;
	for (int i=0;i<r;i++) p2+=q[i]+1;
	p1-=dl; p2+=dr;
	reverse(q+l+1,q+r);
	q[l]+=dr-dl; q[r]+=dl-dr;
	return pair<int,int>(p1,p2);
}
vector<pair<int,int> > getstandard(int *q,int c){
	//for (int i=0;i<=c;i++) cout<<q[i]<<' '; cout<<endl;
	vector<pair<int,int> > ans;
	for (int i=c;i>k+1;i--)
		ans.push_back(Do(q,i-k,0,q[i]));
	//for (int i=0;i<=c;i++) cout<<q[i]<<' '; cout<<endl;
	if (k%2==1){
		for (int i=1;i<=k+1;i++){
			ans.push_back(Do(q,0,0,q[k]));
			ans.push_back(Do(q,1,q[1],q[k+1]));
		}
	}
	else{
		for (int i=1;i<=k+1;i++){
			ans.push_back(Do(q,0,0,q[k]));
			ans.push_back(Do(q,1,q[1],0));
		}
	}
	//for (int i=0;i<=c;i++) cout<<q[i]<<' '; cout<<endl;
	return ans;
}
void print(vector<pair<int,int> > ans){
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%d %d\n",i.first,i.second);
}
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s%s",s1+1,s2+1);
	int c1=0,c2=0;
	for (int i=0;i<=n;i++)
		q1[i]=0,q2[i]=0;
	for (int i=1;i<=n;i++){
		c1+=(s1[i]=='1');
		c2+=(s2[i]=='1');
		q1[c1]+=(s1[i]=='0');
		q2[c2]+=(s2[i]=='0');
	}
	if (c1!=c2){
		puts("-1");
		return;
	}
	if (c1<k||!k){
		for (int i=1;i<=n;i++)
			if (s1[i]!=s2[i]){
				puts("-1");
				return;
			}
		puts("0");
		return;
	}
	if (c1==k){
		vector<pair<int,int> > ans;
		bool flag=1;
		for (int j=1;j<c1;j++)
			if (q1[j]!=q2[c1-j]) flag=0;//cout<<j<<' '<<q1[j]<<' '<<q2[c1-j]<<endl;
		if (!flag){
			ans.push_back(pair<int,int>(q1[0]+1,n-q1[c1]));
			reverse(q1+1,q1+c1);
		}
		flag=1;
		for (int j=1;j<c1;j++)
			if (q1[j]!=q2[c1-j]) flag=0;
		if (flag==0){
			puts("-1");
			return;
		}
		int l=q1[0]+1,r=n-q1[c1];
		if (q1[0]>q2[0]) l-=q1[0]-q2[0];
		else r+=q2[0]-q1[0];
		ans.push_back(pair<int,int>(l,r));
		print(ans);
		return; 
	}
	vector<pair<int,int> > op1=getstandard(q1,c1);
	vector<pair<int,int> > op2=getstandard(q2,c2);
	for (int i=0;i<=c1;i++)
		if (q1[i]!=q2[i]){
			puts("-1");
			return;
		}
	for (;op2.size();){
		op1.push_back(op2.back());
		op2.pop_back();
	}
	print(op1);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
}