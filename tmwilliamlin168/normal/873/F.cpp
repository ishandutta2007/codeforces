#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for(int i=0; i<n-1-i; ++i) {
		swap(s1[i], s1[n-1-i]);
		swap(s2[i], s2[n-1-i]);
	}
	long long ans=0;
	for(int i=0; i<n; ++i) {
		if(s2[i]=='0') {
			ans=n-i;
			break;
		}
	}
	if(!ans) {
		cout << 0;
		return 0;
	}
	int *sa = new int[n], *sa2 = new int[n], *cl = new int[n], *cl2 = new int[n], *cnt = new int[n], *rank = new int[n], *lcp = new int[n];
	for(int i=0; i<n; ++i) {
		sa[i]=i;
		cl[i]=s1[i];
	}
	sort(sa, sa+n, [&s1](const int &a, const int &b) {
		return s1[a]==s1[b]?a>b:s1[a]<s1[b];
	});
	for(int len=1; len<n; len*=2) {
		memcpy(cl2, cl, 4*n);
		for(int i=0; i<n; ++i) {
			cl[sa[i]]=i>0&&cl2[sa[i-1]]==cl2[sa[i]]&&sa[i-1]+len<n&&cl2[sa[i-1]+len/2]==cl2[sa[i]+len/2]?cl[sa[i-1]]:i;
			cnt[i]=i;
		}
		memcpy(sa2, sa, 4*n);
		for(int i=0; i<n; ++i)
			if(sa2[i]-len>=0)
				sa[cnt[cl[sa2[i]-len]]++]=sa2[i]-len;
	}
	for(int i=0; i<n; ++i)
		rank[sa[i]]=i;
	for(int i=0, k=0; i<n; ++i, k-=k>0) {
		if(rank[i]>=n-1)
			continue;
		for(int j=sa[rank[i]+1]; max(i, j)+k<n&&s1[i+k]==s1[j+k]; ++k);
		lcp[rank[i]]=k;
	}
	vector<int> lcp2;
	int i=0;
	while(s2[sa[i]]=='1')
		++i;
	for(int c=lcp[i]; i<n-1; ++i) {
		if(s2[sa[i+1]]=='1')
			c=min(lcp[i+1], c);
		else {
			lcp2.push_back(c);
			c=lcp[i+1];
		}
	}
	int *lcpl = new int[lcp2.size()], *lcpr = new int[lcp2.size()];
	for(int i=0; i<lcp2.size(); ++i) {
		lcpl[i]=i-1;
		while(lcpl[i]!=-1&&lcp2[lcpl[i]]>=lcp2[i])
			lcpl[i]=lcpl[lcpl[i]];
	}
	for(int i=lcp2.size()-1; i>=0; --i) {
		lcpr[i]=i+1;
		while(lcpr[i]!=lcp2.size()&&lcp2[lcpr[i]]>=lcp2[i])
			lcpr[i]=lcpr[lcpr[i]];
	}
	for(int i=0; i<lcp2.size(); ++i)
		ans=max((long long)lcp2[i]*(lcpr[i]-lcpl[i]), ans);
	cout << ans;
}