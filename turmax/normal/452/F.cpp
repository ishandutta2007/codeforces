#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+5;
int a[maxn];
vector<int> t;
int sz=maxn;

void init (int nn)
{
	sz = nn;
	t.assign (nn, 0);
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
	for (; i < sz; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init(maxn);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {cin>>a[i];}
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        if(x<=(n/2))
        {
            if(sum(1,2*x-1)%2==1) {cout<<"YES";return 0;}
        }
        else
        {
            if(sum(2*x-n,n)%2==1) {cout<<"YES";return 0;}
        }
        inc(x,1);
    }
    cout<<"NO";
    return 0;
}