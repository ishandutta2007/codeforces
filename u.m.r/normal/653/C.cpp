#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[MAXN];
vector<int> Q;
vector<PII> P;

int check(int i){
	if (i & 1)
		return a[i] < a[i+1];
	else
		return a[i] > a[i+1];
}

int main(){
	int n ;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = 10000000;
	a[n+1] = ((n & 1) ? 10000000 : -1);
	Q.clear();
	for(int i = 1; i <= n; i++)
		if (i & 1){
			if (a[i] >= a[i+1])
				Q.push_back(i), Q.push_back(i+1);
		}
		else{
			if (a[i] <= a[i+1])
				Q.push_back(i), Q.push_back(i+1);
		}
	sort(Q.begin(), Q.end());
	Q.erase(unique(Q.begin(), Q.end()), Q.end());

//	for(int i = 0; i < Q.size(); i++)
//		cout<<Q[i]<<' ';cout<<endl;

	if (Q.size() > 10){
		puts("0");
		return 0;
	}
	int ans = 0;
	P.clear();
	for(int j = 0; j < Q.size(); j++){
		int p = Q[j];
		for(int i = 1; i <= n; i++)
			if (p != i){
				swap(a[p], a[i]);
				int flag = check(i-1) & check(i);
				for(int k = 0; k < Q.size(); k++)
					flag &= check(Q[k]) & check(Q[k]-1);
				if (flag) P.push_back(PII(min(p,i), max(p,i)));
				swap(a[p], a[i]);
			}
	}
//	for(int i = 0; i < P.size(); i++)
//		cout<<P[i].first<<' '<<P[i].second<<endl;cout<<endl;

	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	cout<<P.size()<<endl;
	return 0;
}