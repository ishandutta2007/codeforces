#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define pli pair<long long,int>

#define Fi first
#define Se second
#define N_ 280

int A[N_], B[N_], X[N_], n, Good[N_], chk[N_], R[N_];
vector<int>H[8];
vector<int>U[8];
vector<int>Z[8];
vector<pii>Ans;
int OA[8], OB[8];
void Add(int a, int b){
	Ans.push_back({a,b});
}
int main() {
	int i, j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		A[i] = a+b*2+c*4;
		U[A[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		B[i] = a+b*2+c*4;
	}
	for(i=1;i<=n;i++){
		X[i] = (A[i]&B[i]);
		//printf("%d %d %d\n",i,X[i],A[i]);
	}
	Good[7]=Good[0]=1;
	while(1){
		int s1=0,s2=0;
		for(i=0;i<8;i++)s1+=Good[i];
		for(i=0;i<8;i++){
			if(!Good[i])continue;
			for(auto &t : U[i]){
				if(!Good[X[t]]){
					Z[X[t]].push_back(t);
					Good[X[t]]=1;
					//printf("%d %d\n",X[t],t);
				}
			}
		}
		for(i=1;i<=n;i++){
			if(Good[A[i]]){
				if(!OA[A[i]])OA[A[i]]=i;
				if(!OB[X[i]])OB[X[i]]=i;
			}
		}
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if((OA[i]||OB[i])&&(OA[j]||OB[j])&&!Good[i|j]){
					Z[i|j].push_back(max(OA[i],OB[i]));
					Z[i|j].push_back(max(OA[j],OB[j]));
					//printf("%d %d %d\n",i,j,i|j);
					Good[i|j]=1;
				}
			}
		}
		for(i=0;i<8;i++)s2+=Good[i];
		if(s1==s2)break;
	}
	for(i=0;i<8;i++){
		if(!U[i].empty() && !Good[i]){
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	for(i=0;i<8;i++){
		for(auto &t : Z[i]){
			chk[t] = 1;
		}
	}
	for(i=1;i<=n;i++){
		R[i] = 1;
		if(A[i]==1||A[i]==2||A[i]==4)R[i]=0;
	}
	for(i=1;i<8;i++){
		if(U[i].empty())continue;
		int zz = 0;
		for(auto &t : U[i]){
			if(!chk[t])zz=t;
		}
		if(i==7)zz=1;

		if(zz){
			H[i].push_back(zz);
			R[zz] = 0;
			for(auto &t : U[i]){
				if(t!=zz){
					Add(zz,t);
				}
			}
		}
		else{
			for(auto &t : U[i]){
				H[i].push_back(t);
			}
		}
		for(auto &t : H[i]){
			for(auto &z : Z[i]){
				Add(z,t);
			}
		}
	}
	for(i=1;i<=n;i++)printf("%d ", R[i]);
	puts("");
	printf("%d\n",Ans.size());
	if(Ans.size()>264){
		while(1){}
	}
	for(auto &t : Ans)printf("%d %d\n",t.first,t.second);
}