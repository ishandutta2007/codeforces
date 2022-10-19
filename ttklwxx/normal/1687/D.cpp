#include <bits/stdC++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e6+2;
vector<int> e[N];
struct Q
{
	int id;
	mutable int len,t;
	bool operator<(const Q &o) const {return id<o.id;}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j;
	cin>>n;
	vector<int> a(n);
	for (int &x:a) cin>>x;
	a.resize(unique(all(a))-a.begin());
	n=a.size();
	set<Q> s;
	for (i=1;i<n;i++) s.insert({i,a[i]-a[i-1],0}),e[a[i]-a[i-1]].push_back(i);
	for (i=1;;i++)
	{
		for (int x:e[i])
		{
			auto it=s.find({x,i,0});
			assert(it!=s.end());
			auto L=it==s.begin()?s.end():prev(it),R=next(it);
			if (L!=s.end()&&L->t&&R!=s.end()&&R->t)
			{
				L->len+=i+R->len;
				s.erase(it);
				s.erase(R);
			}
			else if (L!=s.end()&&L->t)
			{
				L->len+=i;
				s.erase(it);
			}
			else if (R!=s.end()&&R->t)
			{
				R->len+=i;
				s.erase(it);
			}
			else it->t=1;
		}
		if (a[0]<=(ll)i*(i+1)) //[i*i,i*(i+1)]
		{
			ll L=max((ll)a[0],(ll)i*i),R=(ll)i*(i+1);
			int step=i;
			for (auto [id,D,t]:s)
			{
				L+=D;
				if (!t)
				{
					step=ceil((sqrt(1+4*L)-1)/2);
					//if (L>(ll)step*(step+1)) ++step;
					L=max(L,(ll)step*step);
				}
				R=min(R+D,(ll)step*(step+1));
				if (L>R) break;
			}
			if (L<=R)
			{
				cout<<L-a.back()<<endl;
				return 0;
			}
		}
	}
}