#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int N=100050;
vector<int> a;
int main()
{
	int n,i,cnt=0;
	scanf("%i",&n);
	a.resize(n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int sol=a.size();
	for(i=0;i<a.size();i++) if(a[i]==0) sol--;
	printf("%i\n",sol);
	return 0;
}