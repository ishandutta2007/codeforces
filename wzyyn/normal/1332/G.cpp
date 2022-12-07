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
const int N=200005;
int a[N],n,Q;
int ri3[N],ri4[N];
vector<int> ans3[N],ans4[N];
void init_ans_3(){
	static int q[N];
	static int le[N],ri[N];
	a[0]=a[n+1]=-(1<<30);
	int t=0;
	q[++t]=0;
	For(i,1,n){
		for (;a[q[t]]>=a[i];--t);
		le[i]=q[t]; q[++t]=i;
	}
	t=0;
	q[++t]=n+1;
	Rep(i,n,1){
		for (;a[q[t]]>=a[i];--t);
		ri[i]=q[t]; q[++t]=i;
	}
	For(i,1,n)
		if (le[i]!=0&&ri[i]!=n+1)
			if (ri[i]<ri3[le[i]]){
				ri3[le[i]]=ri[i];
				ans3[le[i]]=vector<int>{le[i],i,ri[i]};
			}
	For(i,1,n)
		a[i]=(1<<30)-a[i];
}
void init_3(){
	For(i,1,n+1) ri3[i]=n+1;
	init_ans_3();
	init_ans_3();
	Rep(i,n,1)
		if (ri3[i+1]<ri3[i]){
			ri3[i]=ri3[i+1];
			ans3[i]=ans3[i+1];
		}
}
int find(int *q,int t,int v){
	int l=1,r=t,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (q[mid]<=v)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return q[ans];
}
void init_4(){
	For(i,1,n+1) ri4[i]=n+1;
	static int q1[N],q2[N],S[N];
	static vector<int> op[N];
	static set<int> SS;
	int t1=0,t2=0;
	Rep(i,n,1){
		for (;t1&&a[q1[t1]]<a[i];--t1)
			if (++S[q1[t1]]==2) op[i].PB(q1[t1]);
		for (;t2&&a[q2[t2]]>a[i];--t2)
			if (++S[q2[t2]]==2) op[i].PB(q2[t2]);
		q1[++t1]=q2[++t2]=i;
	}
	t1=0,t2=0;
	Rep(i,n,1){
		for (;t1&&a[q1[t1]]<=a[i];--t1);
		for (;t2&&a[q2[t2]]>=a[i];--t2);
		q1[++t1]=q2[++t2]=i;
		for (auto j:op[i]) SS.insert(j);
		if (t1==1||t2==1) continue;
		set<int>::iterator it=SS.lower_bound(max(q1[t1-1],q2[t2-1]));
		if (it==SS.end()) continue;
		int ed=*it;
		int m1=find(q1,t1,ed);
		int m2=find(q2,t2,ed);
		if (m1>m2) swap(m1,m2);
		if (ed<ri4[i]){
			ri4[i]=ed;
			ans4[i]=vector<int>{i,m1,m2,ed};
		}
	}
	Rep(i,n,1)
		if (ri4[i+1]<ri4[i]){
			ri4[i]=ri4[i+1];
			ans4[i]=ans4[i+1];
		}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	init_3(); init_4();
	//For(i,1,n) cout<<ri3[i]<<' '<<ri4[i]<<endl;
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (r>=ri4[l]){
			printf("4\n");
			for (auto j:ans4[l]) printf("%d ",j);
			puts("");
		}
		else if (r>=ri3[l]){
			printf("3\n");
			for (auto j:ans3[l]) printf("%d ",j);
			puts("");
		}
		else
			puts("0\n");
	}
}