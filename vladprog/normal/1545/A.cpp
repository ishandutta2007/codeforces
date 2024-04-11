#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int t[N];

int n;

void init ()
{
	for(int i=0;i<=n;i++)
        t[i]=0;
}

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i <= n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

int a[N],cnt[N];
vector<int> st[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int> compress;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            compress[a[i]];
        for(auto[it,i]=pair(compress.begin(),1);it!=compress.end();it++,i++)
            it->y=i;
        for(int i=1;i<=n;i++)
            a[i]=compress[a[i]];
        init();
        for(int i=1;i<=n;i++)
            cnt[i]=sum(a[i]+1,n),
            inc(a[i],1);
        init();
        for(int i=n;i>=1;i--)
            cnt[i]+=sum(1,a[i]-1),
            inc(a[i],1);
        for(int i=1;i<=n;i++)
            st[i].clear();
        for(int i=1;i<=n;i++)
        {
            st[a[i]].push_back(cnt[i]%2);
            if(st[a[i]].size()>=2&&
               *st[a[i]].rbegin()==*next(st[a[i]].rbegin()))
                st[a[i]].pop_back(),
                st[a[i]].pop_back();
        }
        bool yes=true;
        for(int i=1;i<=n;i++)
            if(st[i].size()>1||st[i].size()==1&&st[i].front()==1)
                yes=false;
        cout<<(yes?"YES\n":"NO\n");
    }
}