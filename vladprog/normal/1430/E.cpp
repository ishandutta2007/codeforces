#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],t[N];

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < N; i = (i | (i+1)))
		t[i] += delta;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    vector<int> pos[26];
    for(int i=n-1;i>=0;i--)
        pos[s[i]-'a'].push_back(i);
    for(int i=n-1;i>=0;i--)
    {
        a[pos[s[i]-'a'].back()]=n-1-i;
        pos[s[i]-'a'].pop_back();
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=i-sum(a[i]),
        inc(a[i],1);
    cout<<ans;
}