/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int find(int x,int* link) {
while (x != link[x]) x = link[x];
return x;
}

void unite(int a, int b,int* link,int *c,int* size) {
a = find(a,link);
b = find(b,link);
if (size[a] < size[b]) swap(a,b);
size[a] += size[b];
c[a] = min(c[a],c[b]);
link[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	int c[n+1],a[n+1],link[n+1],size[n+1];
	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) size[i] = 1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		link[i]=a[i];
	}
	long long int total=0;
	long long int arr[n+1]={0};
	for(int z=1;z<=n;z++)
	{
		int i1=z;
		while(arr[i1]==0 && link[i1]!=i1)
		{
			arr[i1]=z;
			i1=link[i1];
		}

		if(link[i1]!=i1 && arr[i1]==z)
		{
                        arr[i1]=z;
			int i2 = i1;
			int lowestcost = c[i1];
			i2=link[i2];
			while(i2!=i1)
			{
				lowestcost = min(lowestcost,c[i2]);
                                i2=link[i2];
			}
			total+=lowestcost;
		}
		else if(link[i1]==i1 && arr[i1]==0)
		{
			total+=c[i1];
			arr[i1]=z;
		}
	}
    cout<<total;
     return 0;
}