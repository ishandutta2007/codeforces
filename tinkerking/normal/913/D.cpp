#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,TT;
struct problem
{
	int a,t,num;
}p[200010],pa[200010],pt[200010];
bool cmpa(problem p1,problem p2){
	return p1.a < p2.a;
}
bool cmpt(problem p1,problem p2){
	return p1.t < p2.t;
}
struct FenwickTree
{
	int T[200010];
	void clear(){memset(T,0,sizeof(T));}
	int lowbit(int x){return x&-x;}
	void add(int x,int y){while(x<=N){T[x]+=y;x+=lowbit(x);}}
	int get(int x){int s = 0;while(x){s += T[x];x -= lowbit(x);	}return s;}
}T1,T2;

int pos[200010];

bool check(int permit,int mid){
	return T1.get(mid) <= TT && T2.get(mid) <= permit;
}

int main()
{
	scanf("%d%d",&N,&TT);
	for (int i=1;i<=N;i++)scanf("%d%d",&p[i].a,&p[i].t),p[i].num = i,pa[i] = pt[i] = p[i];
	sort(pa+1,pa+N+1,cmpa);
	sort(pt+1,pt+N+1,cmpt);
	for (int i=1;i<=N;i++)pos[pt[i].num] = i;
	T1.clear();
	T2.clear();
	int solvemost = 0, bestpermit = 0;
	int now = N;
	for (int permit=N;permit>=1;permit--){
		//printf("permit = %d\n",permit);
		while(now > 0 && pa[now].a >= permit)
		{
			int NN = pa[now].num;
			T1.add(pos[NN],p[NN].t);
			T2.add(pos[NN],1);
			//printf("add %d %d %d\n",pos[NN],pa[now].a,pa[now].t);
			now--;
		}
		int L = 0,R = N;
		if (check(permit,R))
		{
			//puts("fuck");
			int vv = T2.get(R);
			//printf("vv = %d\n",vv);
			if (vv > solvemost){
				solvemost = vv;
				bestpermit = permit;
			}
			continue;
		}
		while(L < R - 1){
			int mid = (L + R) >> 1;
			if (check(permit,mid))
				L = mid;
			else
				R = mid;
		}
		int vv = T2.get(L);
		//printf("%d\n ",vv);
		if (vv > solvemost){
			solvemost = vv;
			bestpermit = permit;
		}
		continue;
	}
	vector<int>ans;
	int cnt = 0, sum = 0;
	for (int i=1;i<=N;i++)
	if (pt[i].a >= bestpermit && cnt + 1 <= bestpermit && sum + pt[i].t <= TT)
	{
		cnt++;
		sum += pt[i].t;
		ans.push_back(pt[i].num);
	}
	printf("%d\n%d\n",ans.size(),ans.size());
	for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}