#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PXX pair<long long, long long> 
#define pb pop_back

int n, res=1000000000, tmp;
set<PXX> S;//how much to float
set<PXX>::iterator it;
vector<PXX> V;//how much ballons
PXX T[300003];

int main()
{
	//ios_base::sync_with_stdio(0);
	LL a, b;
	scanf("%d%lld%lld", &n, &a, &b);
	for(int i=1; i<n; i++)
	{
	  LL x, y;
	  scanf("%lld%lld", &x, &y);
	  T[i]=MP(x, y);
	  if(x>a)
	  {
	    tmp++;
	    S.insert(MP(y-x+1, i));
	  }
	  else
	    V.PB(MP(x, i));
	}
	sort(V.begin(), V.end());
	res=tmp+1;
	while(a>0 && !S.empty())
	{
	  it=S.begin();
	  if(it->F>a)
	    break;
	  a-=it->F;
	  S.erase(it);
	  tmp--;
	  while(!V.empty() && V[V.size()-1].F>a)
	  {
	    int ind=V[V.size()-1].S;
	    V.pb();
	    tmp++;
	    S.insert(MP(T[ind].S-T[ind].F+1, ind));
	  }
	  res=min(res, tmp+1);
	}
	printf("%d\n", res);
	return 0;
}