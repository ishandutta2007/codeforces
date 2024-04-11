#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int endd, n, k, b, c;
vector<int> V[5];
int T[200005];
LL res=1000000000000000000LL, r;

LL getres(int ind)
{
	int l=endd-T[ind];
	return (LL)(l/5)*b+(l%5)*c;
}

struct user
{
	int ind;
};

bool operator<(user x, user y)
{
	if(getres(x.ind)==getres(y.ind))
		return x.ind<y.ind;
	return getres(x.ind)>getres(y.ind);
}

set<user> se;

void add(int ind)
{
	user lol;
	lol.ind=ind;
	if((int)se.size()<k)
	{
		r+=getres(ind);
		se.insert(lol);
		//printf("sajz=%d %d\n", (int)se.size(), lol.ind);
		return;
	}
	set<user>::iterator it=se.begin();
	LL qwe=getres((*it).ind), asd=getres(ind);
	if(qwe>asd)
	{
		//printf("           %d %d %lld %lld\n", ind, end, qwe, asd);
		r-=qwe;
		r+=asd;
		se.erase(it);
		//printf("           %d %d\n", (int)se.size(), lol.ind);
		//if(se.find(lol)!=se.end())
		//	printf("japierdoleeeeeee\n");
		se.insert(lol);
		//printf("                %d\n", (int)se.size());
	}
	//printf("sajz=%d\n", (int)se.size());
}

void solve(int ind)
{
	//if(ind!=2)
	//	return;
	//printf("lol %d\n", (int)V[2].size());
	//for(int i=0; i<(int)V[2].size(); i++)
	//	printf("hehe %d\n", V[2][i]);
	se.clear();
	r=0;
	int tmp=1;
	for(int i=0; i<(int)V[ind].size(); i++)
	{
		if(i>0)
			r+=((LL)b*((V[ind][i]-V[ind][i-1])/5))*(LL)se.size();
		endd=V[ind][i];
		while(tmp<=n && T[tmp]<=V[ind][i])
		{
			//printf("aaaaa %d %d\n", tmp, T[tmp]);
			add(tmp);
			tmp++;
		}
		//printf("%d %d %d %d %d\n", end, ind, i, r, (int)se.size());
		if((int)se.size()>=k)
		{
			res=min(res, r);
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d", &n, &k, &b, &c);
	b=min(b, 5*c);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", T+i);
		T[i]+=1000000000;
	}
	sort(T+1, T+n+1);
	for(int i=1; i<=n; i++)
		for(int j=0; j<5; j++)
			V[(T[i]+j)%5].PB(T[i]+j-1000000000);
	for(int i=1; i<=n; i++)
		T[i]-=1000000000;
	for(int i=0; i<5; i++)
	{
		sort(V[i].begin(), V[i].end());
		vector<int>::iterator it=unique(V[i].begin(), V[i].end());
		V[i].resize(distance(V[i].begin(), it));
		solve(i);
	}
	printf("%lld\n", res);
	return 0;
}