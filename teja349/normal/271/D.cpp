//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   

const int MAXN = 1 << 21;
string S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
	N = S.length();
	int i;
	rep(i, N) sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2)
	{
		sort(sa, sa + N, sufCmp);
		rep(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		rep(i, N) pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
}

void buildLCP()
{	int k;
	for(int i = 0, k = 0; i < N; ++i){
		if (pos[i] != N - 1)
		{
			for(int j = sa[pos[i]+1];i+k<N && j+k<N && S[i + k] == S[j + k];)
				++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
		
	} 
}
int sumi=0;
string alp;
int arr[222];
int k;
int compute(int pos){
	int elem=0;
	int conti=0;
	int i;
	if(pos==0){
		elem=sa[pos];
		f(i,elem,N){
			if(arr[S[i]-'a']==0){
				conti++;
			}
			if(conti==k+1)
				break;
			sumi++;
		}
		return 0;
	}
	elem=sa[pos];
		f(i,elem,N){
			if(arr[S[i]-'a']==0){
				conti++;
			}
			if(conti==k+1)
				break;
			if(i-elem>=lcp[pos-1])
				sumi++;

		}
		return 0;

}
int main(){
	cin>>S;
	cin>>alp;
	cin>>k;
	int i;
	rep(i,26){
		arr[i]=alp[i]-'0';
	}
	buildSA();
	buildLCP();
	
	rep(i,N){
		compute(i);
	}
	cout<<sumi<<endl;
}